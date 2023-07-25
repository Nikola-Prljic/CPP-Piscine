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
        double f_ammount;
        double result;
        std::string error;
    };
    typedef std::deque < DateOrError > dequeDate;
    typedef std::deque < DateOrError >::iterator dequeDateItr;
    dequeDate _data;
    dequeDate _csv_data;
    bool dateInRange( std::stringstream &stream, int &ymd, char split, int start, int end);
    void vaildValue( std::stringstream &stream, DateOrError *tmp);

public:

    BitcoinExchange( const std::string argv1 );
    bool strToFloat( std::string str, double &f);
    int open_file( std::ifstream &file, const std::string file_path );
    void save_line( std::string date );
    void saveCsvDate( std::string line );
    void print_data();
    void print_csv_data();
    dequeDateItr findNextYear( dequeDateItr itr );
    void DoBtcExchange();
};

#endif