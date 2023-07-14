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
        int ammount;
        float f_ammount;
        std::string error;
    };
    std::vector < DateOrError > _data;

    bool dateInRange(std::stringstream &stream, int &ymd, char split, int start, int end);

public:

    BitcoinExchange();
    void vaildValue( std::stringstream &stream, DateOrError *tmp);
    void open_file( std::ifstream &file, char *file_path );
    void save_line( std::string date );
    void print_data();
};

#endif