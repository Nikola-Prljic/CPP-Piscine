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
            std::cout << _data[i].month << "-";
            std::cout << _data[i].day << " | ";
            std::cout << _data[i].f_ammount << std::endl;
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

//returns the index of next year
std::vector< BitcoinExchange::DateOrError >::iterator BitcoinExchange::findNextYear( vectorDate::iterator itr, vectorDate::iterator end )
{
    int year = itr->year;
    if( itr->year > _csv_data.back().year)
        return itr;
    for(size_t x = 0; x < _csv_data.size();)
    {
        if( year == itr->year)
            return itr;
        itr++;
        if(itr == end)
        {
            x = 0;
            year++;
        }
    }
    return itr;
}

int BitcoinExchange::findNextMonth( int start, size_t year_index )
{
    for(size_t x = year_index; x < _csv_data.size();)
    {
        if( start == _csv_data[x].month)
            return x + 1;
        x++;
        if( x == 12 )
        {
            x = year_index;
            start++;
        }
    }
    return -1;
}

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