#include "BitcoinExchange.hpp"

bool BitcoinExchange::DateOrError::operator<( const DateOrError& other ) const
{
    if( _year != other._year )
        return _year < other._year;
    if( _month != other._month )
        return _month < other._month;
    return _day < other._day;
}

BitcoinExchange::BitcoinExchange( const std::string &argv1 ) : _csv_data()
{
    std::ifstream inputFile;

    if( open_file( inputFile, "data.csv") )
        return ;
    loop_filestream_handle_data( inputFile, &BitcoinExchange::saveCsvDate, "date,exchange_rate" );
    if( _csv_data.empty() == true ){
        std::cout << "Error\nNo valid data from data.csv" << std::endl;
        return ;
    }
    if( open_file( inputFile, argv1 ) )
        return ;
    loop_filestream_handle_data( inputFile, &BitcoinExchange::processInput, "date | value" );
}

int BitcoinExchange::open_file( std::ifstream &file, const std::string &file_path )
{
    char c;
    file.open( file_path.c_str() );
    if(file.is_open() == false ){
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    file.get(c);
    if( c == 0 ){
        std::cerr << "Error: " << file_path << " is empty." << std::endl;
        return (1);
    }
    file.seekg ( 0, file.beg );
    return (0);
}

void BitcoinExchange::loop_filestream_handle_data( std::ifstream &inputFile, void (BitcoinExchange::*func)(), std::string ignore )
{
    getline( inputFile, line );
    if( line != ignore )
        (this->*func)();
    while ( getline ( inputFile, line ) )
        (this->*func)();
    inputFile.close();
}

void BitcoinExchange::saveTestNumber( std::string &error, int &num)
{
    if(isStringNumeric( line ) == false)
        error = "Error";
    else
        num = std::atoi(line.c_str());
}

void BitcoinExchange::saveCsvDate()
{
    float num;
    DateOrError tmp;
    std::stringstream stream(line);

    if( line.empty() == true )
        return ;
    getline( stream, line, '-' );
    saveTestNumber( tmp._error, tmp._year );
    getline( stream, line, '-' );
    saveTestNumber( tmp._error, tmp._month );
    getline( stream, line, ',' );
    saveTestNumber( tmp._error, tmp._day );
    getline( stream, line );
    if( validDate( tmp._year, tmp._month, tmp._day ) == false || strToFloat( line, num ) == false )
        std::cout << "Error: at data.csv: " << line << std::endl;
    else if( tmp._error.empty() == true )
        _csv_data.insert( std::make_pair( tmp, num ) );
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

void BitcoinExchange::processInput()
{
    float ammount = 0;
    DateOrError tmp(0, 0, 0);
    std::string date;
    std::stringstream stream_YYYY_MM_DD( line );
    
    getline( stream_YYYY_MM_DD, date, ' ' );
    if( line.empty() == true )
        return ;
    switch ( test_line( tmp, ammount ) )
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

int BitcoinExchange::test_line( DateOrError &tmp, float &ammount )
{
    std::stringstream stream(line);

    if( save_date(stream, tmp._year, '-' ) == false || save_date( stream, tmp._month, '-' ) == false || save_date(stream, tmp._day, ' ' ) == false )
        return ErrorDate;
    if( validDate( tmp._year, tmp._month, tmp._day) == false )
        return ErrorDate;
    if( vaildValue( stream, ammount ) == false )
        return ErrorValue;
    return FindExchangeRate;
}

bool BitcoinExchange::isStringNumeric( const std::string &str )
{
    for(std::string::const_iterator itr = str.begin(); itr != str.end(); itr++)
        if(std::isdigit(*itr) == false)
            return false;
    return true;
}

bool BitcoinExchange::save_date( std::stringstream &stream, int &ymd, const char &split )
{
    std::string tmp_line;

    getline(stream, tmp_line, split);
    if( isStringNumeric( tmp_line ) == false )
        return false;
    ymd = std::atoi(tmp_line.c_str());
    return true;
}

bool BitcoinExchange::vaildValue( std::stringstream &stream, float &ammount )
{
    std::string str;

    getline(stream, str);
    if(str[0] != '|' || str[1] != ' ') {
        std::cout << "Error: format needs to be: \"date | value\"" << std::endl;
        return false;
    }
    str.erase(0, 2);
    if( strToFloat( str, ammount) == false ) {
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

BitcoinExchange::BitcoinExchange( const BitcoinExchange &src ) : _csv_data(src._csv_data), line(src.line) { return ; }

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &src )
{
    if(this == &src)
        return *this;
    _csv_data = src._csv_data;
    line = src.line;
    return *this;
}
