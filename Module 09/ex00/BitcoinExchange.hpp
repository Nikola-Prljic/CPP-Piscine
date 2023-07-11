#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>

class BitcoinExchange
{
private:

    struct DateOrError { 
        int year; 
        int month; 
        int day; 
        int ammount;
        std::string error;
    };

    std::vector < DateOrError > _data;
    int input_error( std::string line );
    void dateInRange(std::stringstream &stream, DateOrError &tmp, int &ymd, char split, int start, int end);

public:

    BitcoinExchange();
    void open_file( std::ifstream &file, char *file_path );
    int valid_line( std::string line );
    void save_line( std::string date );
    void print_data();
};

#endif