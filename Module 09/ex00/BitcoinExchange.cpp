#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() : _data() {}

int BitcoinExchange::input_error( std::string line )
{
    DateOrError tmp;
    std::stringstream stream(line);

    getline(stream, line, '|');
    tmp.error = "Error bad input: " + line;
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

void BitcoinExchange::dateInRange(std::stringstream &stream, DateOrError &tmp, int &ymd, char split, int start, int end)
{
    std::string tmp_line;

    getline(stream, tmp_line, split);
    ymd = std::atoi(tmp_line.c_str());
    if( ymd < start || ymd > end )
        tmp.error = "Error bad input: ";
}

void BitcoinExchange::save_line( std::string line )
{
    DateOrError tmp;
    std::string tmp_line;
    std::stringstream stream(line);

    dateInRange(stream, tmp, tmp.year, '-', 2009, 2022);
    dateInRange(stream, tmp, tmp.month, '-', 1, 12);
    dateInRange(stream, tmp, tmp.day, ' ', 1, 32);

    if(tmp.error.empty() == true)
    {
        getline(stream, tmp_line);
        tmp_line.erase(0, 2);
        tmp.ammount = std::atoi(tmp_line.c_str());
    }
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
