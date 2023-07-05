#include "BitcoinExchange.hpp"
#include <stdlib.h>

BitcoinExchange::BitcoinExchange() : _data() {}

void TmpExit( std::string msg )
{
    std::cout << msg << std::endl;
    exit(1);
}

void BitcoinExchange::valid_date( std::string date )
{
    int i = 0;

    for( ; i < 10; i++)
    {
        if((i == 4 && date[i] != '-') || (i == 7 && date[i] != '-'))
            TmpExit( "wrong!! - " );
        else if(i == 4 || i == 7)
            continue ;
        if(isdigit(date[i]) == 0)
            TmpExit( "wrong!! num " );
    }
    if(date[i] != ' ')
        TmpExit( "wrong!!" );
    i++;
    if(date[i] != '|')
        TmpExit( "wrong!!" );
    i += 2;
    for(; date[i] != '\n' && date[i]; i++)
    {
        if(isdigit(date[i]) == 0 || i > 20)
            TmpExit( "wrong!!" );
    }
}

void BitcoinExchange::save_date( std::string date )
{
    DateOrError tmp;
    std::string year;
    std::stringstream ss(date);

    getline(ss, year, '-');
    tmp.year = atoi(year.c_str());

    getline(ss, year, '-');
    tmp.month = atoi(year.c_str());

    getline(ss, year, ' ');
    tmp.day = atoi(year.c_str());

    getline(ss, year);
    year.erase(0, 2);
    tmp.ammount = atoi(year.c_str());
    _data.push_back(tmp);

    for(std::size_t i = 0; i < _data.size(); i++)
    {
        std::cout << _data[i].year << "-";
        std::cout << _data[i].month << "-";
        std::cout << _data[i].day << " | ";
        std::cout << _data[i].ammount << std::endl;
    }
}

void BitcoinExchange::open_file( std::ifstream &file, char *file_path )
{
    std::string line;

    file.open(file_path);
    if(file.is_open() == false)
    {
        std::cout << "Error: Unable to open file!" << std::endl;
        exit(1);
    }
}
