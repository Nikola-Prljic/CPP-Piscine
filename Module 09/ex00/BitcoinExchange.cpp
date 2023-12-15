#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <ctime>

BitcoinExchange::BitcoinExchange( const std::string &argv1 ) : _csv_data()  
{
    std::ifstream inputFile;
    std::ifstream dataFile;
    std::string line;

    if( open_file( dataFile, "data.csv") )
        return ;
    getline ( dataFile, line );
    if( line != "date,exchange_rate" )
        saveCsvDate( line );
    while ( getline ( dataFile, line ) )
        saveCsvDate( line );
    dataFile.close();
    if( _csv_data.empty() == true )
    {
        std::cout << "Error\nNo valid data from data.csv" << std::endl;
        return ;
    }

    if( open_file( inputFile, argv1) )
        return ;
    while ( getline ( inputFile, line ) )
        save_line( line );
    inputFile.close();
}

int BitcoinExchange::open_file( std::ifstream &file, const std::string &file_path )
{
    std::string line;

    file.open(file_path.c_str());
    if(file.is_open() == false )
    {
        std::cout << "Error: Unable to open file!" << std::endl;
        return (1);
    }
    return (0);
}

bool BitcoinExchange::validDate( const int &year, const int &month, const int &day)
{
    struct tm t = {};

    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    std::time_t ta = std::mktime(&t);
    if ( ta < 0 || year != t.tm_year + 1900 || month != t.tm_mon + 1 || day != t.tm_mday  )
        return false;
    return true;
}

static bool strIsNum( const std::string &str )
{
    for(std::string::const_iterator itr = str.begin(); itr != str.end(); itr++)
        if(std::isdigit(*itr) == false)
            return false;
    return true;
}

bool BitcoinExchange::dateInRange( std::stringstream &stream, int &ymd, const char &split )
{
    std::string tmp_line;

    getline(stream, tmp_line, split);
    if(strIsNum( tmp_line ) == false)
        return false;
    ymd = std::atoi(tmp_line.c_str());
    return true;
}

int BitcoinExchange::test_input_file( DateOrError &tmp, const std::string &line, float &ammount )
{
    std::stringstream stream(line);

    if( dateInRange(stream, tmp._year, '-' ) == false || dateInRange( stream, tmp._month, '-' ) == false || dateInRange(stream, tmp._day, ' ' ) == false )
        return ErrorDate;
    if( validDate( tmp._year, tmp._month, tmp._day) == false )
        return ErrorDate;
    if( vaildValue( stream, ammount ) == false )
        return ErrorValue;
    return FindExchangeRate;
}

void BitcoinExchange::save_line( const std::string &line )
{
    float ammount = 0;
    DateOrError tmp(0, 0, 0);
    std::string date;
    std::stringstream stream_YYYY_MM_DD( line );
    
    getline( stream_YYYY_MM_DD, date, ' ' );
    switch ( test_input_file( tmp, line, ammount ) )
    {
    case ErrorDate:
        std::cout << "Error: bad input => "  + date << std::endl;
        break;
    case ErrorValue:
        break;
    case FindExchangeRate:
        print_data( ammount, tmp );
        break;
    default:
        break;
    }
}

void BitcoinExchange::print_data( const float &ammount, const DateOrError &tmp )
{
    dequeDateItr itr = _csv_data.upper_bound(tmp);

    if(itr != _csv_data.begin() )
        itr--;
    std::cout << tmp._year << "-";
    if(tmp._month < 10)
        std::cout << "0";
    std::cout << tmp._month << "-";
    if(tmp._day < 10)
        std::cout << "0";
    std::cout << tmp._day << " => ";
    std::cout << ammount << " = ";
    std::cout << ammount * itr->second << std::endl;
}

bool BitcoinExchange::vaildValue( std::stringstream &stream, float &ammount )
{
    std::string line;

    getline(stream, line);
    if(line[0] != '|' || line[1] != ' ') {
        std::cout << "Error format needs to be: \"date | value\"" << std::endl;
        return false;
    }
    line.erase(0, 2);
    if( strToFloat( line, ammount) == false ) {
        std::cout << "Error: just numeric input." << std::endl;
        return false;
    }   
    else if( ammount > 1000 ) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    else if( ammount < 0 ) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::strToFloat( const std::string &str, float &f )
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

static void saveTestNum( const std::string &line, std::string &error, int &num)
{
    if(strIsNum( line ) == false)
        error = "Error";
    else
        num = std::atoi(line.c_str());
}

void BitcoinExchange::saveCsvDate( const std::string &line )
{
    float num;
    DateOrError tmp;
    std::string tmp_line;
    std::stringstream stream(line);

    if( line.empty() == true )
    {
        std::cerr << "Error" << std::endl << "Empty line in data.csv " << std::endl;
        return ;
    }
    getline( stream, tmp_line, '-' );
    saveTestNum( tmp_line, tmp._error, tmp._year );
    getline( stream, tmp_line, '-' );
    saveTestNum( tmp_line, tmp._error, tmp._month );
    getline( stream, tmp_line, ',' );
    saveTestNum( tmp_line, tmp._error, tmp._day );
    getline( stream, tmp_line );
    if( validDate( tmp._year, tmp._month, tmp._day ) == false || strToFloat( tmp_line, num ) == false )
        std::cout << "Error" << std::endl << "In data.csv: " << tmp_line << std::endl;
    else if( tmp._error.empty() == true )
        _csv_data.insert( std::make_pair( tmp, num ) );
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &src ) : _csv_data(src._csv_data) { return ; }

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &src )
{
    if(this == &src)
        return *this;
    _csv_data = src._csv_data;
    return *this;
}
