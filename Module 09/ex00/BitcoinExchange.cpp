#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() : _data() {}

void TmpExit( std::string msg )
{
    std::cout << msg << std::endl;
    std::exit(1);
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

void BitcoinExchange::save_date( std::string line )
{
    DateOrError tmp;
    std::string year;
    std::stringstream stream(line);

    getline(stream, year, '-');
    tmp.year = std::atoi(year.c_str());

    getline(stream, year, '-');
    tmp.month = std::atoi(year.c_str());

    getline(stream, year, ' ');
    tmp.day = std::atoi(year.c_str());

    getline(stream, year);
    year.erase(0, 2);
    tmp.ammount = std::atoi(year.c_str());
    _data.push_back(tmp);
}

void BitcoinExchange::open_file( std::ifstream &file, char *file_path )
{
    std::string line;

    file.open(file_path);
    if(file.is_open() == false)
    {
        std::cout << "Error: Unable to open file!" << std::endl;
        std::exit(1);
    }
}

void BitcoinExchange::print_data()
{
    for(std::size_t i = 0; i < _data.size(); i++)
    {
        std::cout << _data[i].year << "-";
        std::cout << _data[i].month << "-";
        std::cout << _data[i].day << " | ";
        std::cout << _data[i].ammount << std::endl;
    }
}