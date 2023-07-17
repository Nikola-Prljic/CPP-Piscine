#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() : _data(), _csv_data() {}

bool strIsNum( std::string str )
{
    for(std::string::iterator itr = str.begin(); itr != str.end(); itr++)
        if(std::isdigit(*itr) == false)
            return false;
    return true;
}

bool BitcoinExchange::strToFloat( std::string str, float &f)
{
    bool dot = false;
    std::stringstream ss(str);

    for(int i = 0; str[i]; i++)
    {
        if(str[i] == '.' && dot == false)
            dot = true;
        else if(isdigit(str[i]) == false)
            return false;
    }
    if (!(ss >> f))
        return false;
    return true;
}

void BitcoinExchange::vaildValue( std::stringstream &stream, DateOrError *tmp)
{
    std::string line;

    getline(stream, line);
    if(line[0] != '|' || line[1] != ' ')
    {
        tmp->error = "Error format needs to be: \"date | value\"";
        return ;
    }
    line.erase(0, 2);
    if(strToFloat( line, tmp->f_ammount) == false)
        tmp->error = "Error just numeric input.";
    else if( tmp->f_ammount > 1000)
        tmp->error = "Error not more than 1000.";
    else if( tmp->f_ammount < 0)
        tmp->error = "Error no negative numbers.";
}

void saveTestNum( std::string line, std::string &error, int &num)
{
    if(strIsNum( line ) == false)
        error = "Error";
    else
        num = std::atoi(line.c_str());
}

void BitcoinExchange::saveCsvDate( std::string line )
{
    DateOrError tmp;
    std::string tmp_line;
    std::stringstream stream(line);

    getline(stream, tmp_line, '-');
    saveTestNum( tmp_line, tmp.error, tmp.year );
    getline(stream, tmp_line, '-');
    saveTestNum( tmp_line, tmp.error, tmp.month );
    getline(stream, tmp_line, ',');
    saveTestNum( tmp_line, tmp.error, tmp.day );
    getline(stream, tmp_line);
    strToFloat( tmp_line, tmp.f_ammount);
    if(tmp.error.empty() == true)
        _csv_data.push_back(tmp);
}

bool BitcoinExchange::dateInRange( std::stringstream &stream, int &ymd, char split, int start, int end)
{
    std::string tmp_line;

    getline(stream, tmp_line, split);
    if(strIsNum( tmp_line ) == false)
        return false;
    ymd = std::atoi(tmp_line.c_str());
    if( ymd < start || ymd > end )
        return false;
    return true;
}

void BitcoinExchange::save_line( std::string line )
{
    DateOrError tmp;
    std::string date;
    std::stringstream stream(line);
    std::stringstream stream_YYYY_MM_DD(line);
    
    getline(stream_YYYY_MM_DD, date, '|');
    if(dateInRange(stream, tmp.year, '-', 2009, 2022) == false)
        tmp.error = "Error bad input: \""  + date + "\"";
    else if(dateInRange(stream, tmp.month, '-', 1, 12) == false)
        tmp.error = "Error bad input: \""  + date + "\"";
    else if(dateInRange(stream, tmp.day, ' ', 1, 32) == false)
        tmp.error = "Error bad input: \""  + date + "\"";
    else
        vaildValue( stream, &tmp);
    _data.push_back(tmp);
}

void BitcoinExchange::open_file( std::ifstream &file, const char *file_path )
{
    std::string line;

    file.open(file_path);
    if(file.is_open() == false)
    {
        std::cout << "Error: Unable to open file!" << std::endl;
        std::exit(1);
    }
}

void BitcoinExchange::print_data()
{
    for(std::size_t i = 0; i < _data.size(); i++)
    {
        if(_data[i].error.empty() == true)
        {
            std::cout << _data[i].year << "-";
            if(_data[i].month < 10)
                std::cout << "0";
            std::cout << _data[i].month << "-";
            if(_data[i].day < 10)
                std::cout << "0";
            std::cout << _data[i].day << " -> ";
            std::cout << _data[i].result << std::endl;
        }
        else
            std::cout << _data[i].error << std::endl;
    }
}

void BitcoinExchange::print_csv_data()
{
    for(std::size_t i = 0; i < _csv_data.size(); i++)
    {
        if(_csv_data[i].error.empty() == true)
        {
            std::cout << _csv_data[i].year << "-";
            std::cout << _csv_data[i].month << "-";
            std::cout << _csv_data[i].day << ",";
            std::cout << _csv_data[i].f_ammount << std::endl;
        }
        else
            std::cout << _csv_data[i].error << std::endl;
    }
}

//returns the final result
std::deque< BitcoinExchange::DateOrError >::iterator BitcoinExchange::findNextYear( dequeDateItr itr )
{
    dequeDateItr csvItr = _csv_data.begin();

    while(itr->year > csvItr->year && csvItr != _csv_data.end())
        csvItr++;
    csvItr++;
    if(itr->year == csvItr->year)
    {
        csvItr--;
        while(itr->month > csvItr->month)
            csvItr++;
        csvItr++;
        if(itr->month == csvItr->month)
        {
            csvItr--;
            while(itr->day > csvItr->day)
                csvItr++;
        }
        else
            csvItr--;
    }
    else
        csvItr--;
    return csvItr;
}


void BitcoinExchange::DoBtcExchange()
{
    dequeDateItr dataEnd = _data.end();

    for(dequeDateItr dataItr = _data.begin(); dataItr != dataEnd; dataItr++)
        if(dataItr->error.empty() == true)
        {
            dequeDateItr year = findNextYear( dataItr );
            dataItr->result = year->f_ammount * dataItr->f_ammount;
        }
}


/* 
int BitcoinExchange::findNextDay( int start, size_t month_index )
{
    for(size_t x = month_index; x < _csv_data.size();)
    {
        if( start == _csv_data[x].month)
            return x + 1;
        x++;
        if( x == 32 )
        {
            x = month_index;
            start++;
        }
    }
    return -1;
}

std::deque< BitcoinExchange::DateOrError >::iterator BitcoinExchange::findNextMonth( dequeDateItr itrStart, int month, int day)
{
    dequeDateItr csvItr = itrStart;
    while(csvItr != _csv_data.end())
    {
        if(month == csvItr->month)
        {
            itrStart = csvItr;
            break ;
        }
        if( month < csvItr->month)
            return --csvItr;
        csvItr++;
    }
    while(csvItr != _csv_data.end())
    {
        if(day == csvItr->day)
            return csvItr;
        csvItr++;
    }
    return --csvItr;
} */