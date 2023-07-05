#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct DateOrError {
    int year;
    int month;
    int day;
    int ammount;
    std::string error;
};

class BitcoinExchange
{
    private:
        //std::vector< std::vector<int> > _data;
        std::vector < DateOrError > _data;

    public:

        BitcoinExchange();
        void open_file( std::ifstream &file, char *file_path );
        void valid_date( std::string date );
        void save_date( std::string date );

        /* std::vector<std::string> getData(); */
};

#endif