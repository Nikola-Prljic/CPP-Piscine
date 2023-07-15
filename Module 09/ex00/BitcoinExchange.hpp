#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <vector>
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
        std::string error;
    };
    bool dateInRange(std::stringstream &stream, int &ymd, char split, int start, int end);
    void vaildValue( std::stringstream &stream, DateOrError *tmp);

public:
    typedef std::vector < DateOrError > vectorDate;
    vectorDate _data;
    vectorDate _csv_data;

    BitcoinExchange();
    bool strToFloat( std::string str, float &f);
    void open_file( std::ifstream &file, const char *file_path );
    void save_line( std::string date );
    void saveCsvDate( std::string line );
    void print_data();
    void print_csv_data();
    vectorDate::iterator findNextYear( vectorDate::iterator itr, vectorDate::iterator end );
    int findNextMonth( int start, size_t year_index );
    int findNextDay( int start, size_t month_index );
};

#endif