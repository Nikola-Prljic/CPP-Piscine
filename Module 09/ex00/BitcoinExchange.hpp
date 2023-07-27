#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <deque>
# include <sstream>
# include <algorithm>

class BitcoinExchange
{
private:

    struct DateOrError { 
        int year; 
        int month; 
        int day;
        float f_ammount;
        float result;
        std::string error;
    };
    typedef std::deque < DateOrError > dequeDate;
    typedef std::deque < DateOrError >::iterator dequeDateItr;
    dequeDate _data;
    dequeDate _csv_data;

    BitcoinExchange();

    bool dateInRange( std::stringstream &stream, int &ymd, char split, int start, int end);
    void vaildValue( std::stringstream &stream, DateOrError *tmp);
    bool strToFloat( std::string str, float &f);
    int open_file( std::ifstream &file, const std::string file_path );
    void save_line( std::string date );
    void saveCsvDate( std::string line );
    void print_data();
    void print_csv_data();
    dequeDateItr findNextYear( dequeDateItr itr );
    void DoBtcExchange();

public:

    BitcoinExchange( const std::string argv1 );
};

#endif