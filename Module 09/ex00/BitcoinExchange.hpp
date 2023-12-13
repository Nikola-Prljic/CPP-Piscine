#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <sstream>
# include <algorithm>

class BitcoinExchange
{
private:

    struct DateOrError { 
        int _year; 
        int _month; 
        int _day;
        float _result;
        std::string _error;

        DateOrError() {}
        DateOrError( int year, int month, int day) : _year(year), _month(month), _day(day){}

        bool operator<(const DateOrError& other) const {
            if( _year != other._year )
                return _year < other._year;
            if( _month != other._month )
                return _month < other._month;
            return _day < other._day;
        }
    };
    typedef std::map < DateOrError, float> dequeDate;
    typedef std::map < DateOrError, float>::iterator dequeDateItr;
    dequeDate _data;
    dequeDate _csv_data;

    BitcoinExchange();

    int open_file( std::ifstream &file, const std::string file_path );
    void save_line( std::string date );
    bool dateInRange( std::stringstream &stream, int &ymd, char split, int start, int end);
    bool validDate(int year, int month, int day);
    void vaildValue( std::stringstream &stream, DateOrError *tmp, float &ammount);
    bool strToFloat( std::string str, float &f);
    void print_csv_data();

    /*
    void saveCsvDate( std::string line );
    dequeDateItr findNextYear( dequeDateItr itr );w
    void DoBtcExchange();
     */

public:

    BitcoinExchange( const std::string &argv1 );
    BitcoinExchange( const BitcoinExchange &src );
    BitcoinExchange &operator=( const BitcoinExchange &src );
    /* void print_data(); */
};

#endif