#include "BitcoinExchange.hpp"
#include <stdlib.h>

BitcoinExchange::BitcoinExchange() : _data() {}

int BitcoinExchange::input_error( std::string line )
{
    DateOrError tmp;

    tmp.error = "Not a valide input: " + line;
    _data.push_back(tmp);
    return (1);
}

int BitcoinExchange::valid_line( std::string line )
{
    int i = 0;

    for( ; i < 10; i++)
    {
        if((i == 4 && line[i] != '-') || (i == 7 && line[i] != '-'))
            return input_error( line );
        else if(i == 4 || i == 7)
            continue ;
        if(isdigit(line[i]) == 0)
            return input_error( line );
    }
    if(line[i] != ' ')
        return input_error( line );
    i++;
    if(line[i] != '|')
        return input_error( line );
    i += 2;
    for(; line[i] != '\n' && line[i]; i++)
        if(isdigit(line[i]) == 0 || i > 20)
            return input_error( line );
    return 0;
}

void BitcoinExchange::save_date( std::string line )
{
    DateOrError tmp;
    std::string year;
    std::stringstream stream(line);

    getline(stream, year, '-');
    tmp.year = atoi(year.c_str());

    getline(stream, year, '-');
    tmp.month = atoi(year.c_str());

    getline(stream, year, ' ');
    tmp.day = atoi(year.c_str());

    getline(stream, year);
    year.erase(0, 2);
    tmp.ammount = atoi(year.c_str());
    _data.push_back(tmp);
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

void BitcoinExchange::print_data()
{
    for(std::size_t i = 0; i < _data.size(); i++)
    {
        if(_data[i].error.empty() == true)
        {
            std::cout << _data[i].year << "-";
            std::cout << _data[i].month << "-";
            std::cout << _data[i].day << " | ";
            std::cout << _data[i].ammount << std::endl;
        }
        else
            std::cout << _data[i].error << std::endl;
    }
}
