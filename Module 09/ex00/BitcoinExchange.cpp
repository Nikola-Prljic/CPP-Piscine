#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <ctime>

BitcoinExchange::BitcoinExchange( const std::string &argv1 ) : _data(), _csv_data()  
{
    std::ifstream inputFile;
    std::ifstream dataFile;
    std::string line;

    if(open_file( inputFile, argv1))
        return ;
    while ( getline ( inputFile, line ) )
        save_line( line );
    inputFile.close();
    if(open_file( dataFile, "data.csv"))
        return ;
    while ( getline ( dataFile, line ) )
        saveCsvDate( line );  
    dataFile.close();
    DoBtcExchange();
    print_data();
}

bool strIsNum( std::string str )
{
    for(std::string::iterator itr = str.begin(); itr != str.end(); itr++)
        if(std::isdigit(*itr) == false)
            return false;
    return true;
}

bool BitcoinExchange::strToFloat( std::string str, float &f)
{
    int i = 0;
    bool dot = false;

    std::istringstream ss(str);

    if(str[0] == '-')
        i++;
    for(; str[i]; i++)
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
        tmp->error = "Error: just numeric input.";
    else if( tmp->f_ammount > 1000)
        tmp->error = "Error: too large a number.";
    else if( tmp->f_ammount < 0)
        tmp->error = "Error: not a positive number.";
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
    
    getline(stream_YYYY_MM_DD, date, ' ');

    if(dateInRange(stream, tmp.year, '-', 1950, 2023) == false)
        tmp.error = "Error: bad input => "  + date;
    else if(dateInRange(stream, tmp.month, '-', 1, 12) == false)
        tmp.error = "Error: bad input => "  + date;
    else if(dateInRange(stream, tmp.day, ' ', 1, 32) == false)
        tmp.error = "Error: bad input => "  + date;
    else if(validDate(tmp.year, tmp.month, tmp.day) == false)
        tmp.error = "Error: bad input => "  + date;
    else
        vaildValue( stream, &tmp);
    _data.push_back(tmp);
}

int BitcoinExchange::open_file( std::ifstream &file, const std::string file_path )
{
    std::string line;

    file.open(file_path.c_str());
    if(file.is_open() == false)
    {
        std::cout << "Error: Unable to open file!" << std::endl;
        return(1);
    }
    return(0);
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
            std::cout << _data[i].day << " => ";
            std::cout << _data[i].f_ammount << " = ";
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

bool BitcoinExchange::validDate( int year, int month, int day)
{
    struct tm t = {};

    t.tm_year = year;
    t.tm_mon = month;
    t.tm_mday = day;
    std::time_t ta = std::mktime(&t);
    if ( ta < 0 || year != t.tm_year || month != t.tm_mon || day != t.tm_mday )
        return false;
    return true;
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
            if(itr->day != csvItr->day)
                return --csvItr;
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

BitcoinExchange::BitcoinExchange( const BitcoinExchange &src ) : _data(src._data), _csv_data(src._csv_data)
{
    return ;
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &src )
{
    if(this == &src)
        return *this;
    _data = src._data;
    _csv_data = src._csv_data;
    return *this;
}
