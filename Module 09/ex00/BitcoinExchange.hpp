#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <fstream>
# include <sstream>
# include <ctime>
# include <map>

class BitcoinExchange
{
private:

    enum SwitchCases{ ErrorDate=1, ErrorValue=2, FindExchangeRate=3 };

    struct DateOrError {
        int         _year;
        int         _month; 
        int         _day;
        std::string _error;

        DateOrError() {}
        DateOrError( const int &year, const int &month, const int &day) : _year(year), _month(month), _day(day){}

        bool operator<(const DateOrError& other) const;
    };

    typedef std::map < DateOrError, float> dequeDate;
    typedef std::map < DateOrError, float>::iterator dequeDateItr;
    dequeDate _csv_data;
    std::string line;

    void    processInput();
    bool    isStringNumeric( const std::string &str );
    int     test_line( DateOrError &tmp, float &ammount );
    bool    vaildValue( std::stringstream &stream, float &ammount );
    bool    validDate( const int &year, const int &month, const int &day);
    int     open_file( std::ifstream &file, const std::string &file_path );
    bool    save_date( std::stringstream &stream, int &ymd, const char &split );
    
    void    saveCsvDate();
    void    saveTestNumber( std::string &error, int &num);
    bool    strToFloat( const std::string &str, float &f );
    void    print_data( const float &ammount, const DateOrError &tmp );

    void    loop_filestream_handle_data( std::ifstream &inputFile, void (BitcoinExchange::*func)(), std::string ignore );

    BitcoinExchange();

public:

    BitcoinExchange( const std::string &argv1 );
    BitcoinExchange( const BitcoinExchange &src );
    BitcoinExchange &operator=( const BitcoinExchange &src );
};

#endif