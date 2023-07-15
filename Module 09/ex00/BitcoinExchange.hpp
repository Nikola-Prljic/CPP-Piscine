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
    std::vector < DateOrError > _data;
    std::vector < DateOrError > _csv_data;

    bool dateInRange(std::stringstream &stream, int &ymd, char split, int start, int end);
    void vaildValue( std::stringstream &stream, DateOrError *tmp);

public:

    BitcoinExchange();
    bool strToFloat( std::string str, float &f);
    void open_file( std::ifstream &file, const char *file_path );
    void save_line( std::string date );
    void saveCsvDate( std::string line );
    void print_data();
    void print_csv_data();
};

#endif