#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class BitcoinExchange
{
    private:
        std::vector< std::vector<int> > _data;

        BitcoinExchange();

    public:
        BitcoinExchange( char *file_path );

        void open_file( char *file_path );
        void valid_date( std::string date );

        /* std::vector<std::string> getData(); */
};

#endif