#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <vector>

class BitcoinExchange
{
    private:
        std::vector< std::vector<std::string> > _data;

        BitcoinExchange();

    public:
        BitcoinExchange( char *file_path );

        void open_file( char *file_path );
        void valid_input();

        /* std::vector<std::string> getData(); */
};

#endif