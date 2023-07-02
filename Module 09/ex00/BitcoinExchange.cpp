#include "BitcoinExchange.hpp"
#include <stdlib.h>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( char *file_path ) : _data()
{
    open_file( file_path );
}

void BitcoinExchange::valid_date( std::string date )
{
    int i = 0;

    for( ; i < 10; i++)
    {
        if((i == 4 && date[i] == '-') || (i == 7 && date[i] == '-'))
            continue ;
        if(isdigit(date[i]) == 0)
        {
            std::cout << "wrong!!" << std::endl;
            exit(1);
        }
    }
    if(date[i] == ' ')
        i++;
    if(date[i] != '|')
    {
        std::cout << "wrong!!" << std::endl;
        exit(1);
    }

    std::string year;
    std::stringstream ss(date);
    std::vector<int> tmp;

    for(i = 0; i < 2; i++)
    {
        getline(ss, year, '-');
        tmp.push_back(atoi(year.c_str()));
    }
    getline(ss, year, ' ');
    tmp.push_back(atoi(year.c_str()));
    _data.push_back(tmp);
    for(std::size_t i = 0; i < _data[0].size(); i++)
        std::cout << _data[0][i] << std::endl;
}

void BitcoinExchange::open_file( char *file_path )
{
    std::string line;
    std::ifstream file;

    file.open(file_path);
    if(file.is_open() == false)
    {
        std::cout << "Error: Unable to open file!" << std::endl;
        exit(1);
    }
    while ( getline (file, line) )
        valid_date(line);
    /* for(std::vector<std::string>::iterator itr = _data.begin(); itr != _data.end(); itr++)
        std::cout << itr[0] << std::endl; */
    file.close();
}

/* std::vector<std::string> BitcoinExchange::getData() { return _data; } */

/* std::string open_file(char *file_path)
{
    std::ofstream input_file;
    input_file.open(file_path);
    if(input_file.is_open())
    {
        std::cout << "file open faild" << std::endl;
        exit(1);
    }
    return input_file;
} */