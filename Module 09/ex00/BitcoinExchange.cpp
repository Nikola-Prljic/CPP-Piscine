#include "BitcoinExchange.hpp"
#include <stdlib.h>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( char *file_path ) : _data()
{
    open_file( file_path );
}

/* void BitcoinExchange::valid_input()
{   
    std::vector<std::string>::iterator itr = _data.begin();

    for(; itr != _data.end(); itr++)
    {
        itr[0] 
    }
} */

int is_date( std::string date )
{
    int i = 0;

    for( ; date[i]; i++)
    {
        if(i == 9)
            break ;
        if(i == 4 && date[i] == '-')
            continue;
        if(i == 7 && date[i] == '-')
            continue;
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
    return i;
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
    int i = 0;
    while ( getline (file, line) )
    {
        is_date(line);
        /* _data[i].push_back(line);
        _data[i].push_back(line); */
        i++;
    }
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