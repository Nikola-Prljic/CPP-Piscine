#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() : _data() {}

bool strIsNum( std::string str )
{
    for(std::string::iterator itr = str.begin(); itr != str.end(); itr++)
        if(std::isdigit(*itr) == false)
            return false;
    return true;
}

bool strToNumeric( std::stringstream &ss, int &i_ammount, float &f_ammount)
{
    int i;
    float f;
    /* std::stringstream ss(sss.str()); */
    if ((ss >> i))
        i_ammount = i;
    else if ((ss >> f))
        f_ammount = f;
    else
        return false;
    return true;
}

bool BitcoinExchange::dateInRange( std::stringstream &stream, int &ymd, char split, int start, int end)
{
    std::string tmp_line;

    getline(stream, tmp_line, split);
    if(strIsNum( tmp_line ) == false)
        return false;
    ymd = std::atoi(tmp_line.c_str());
    if( ymd < start || ymd > end )
        return false;
    return true;
}


void BitcoinExchange::vaildValue( std::stringstream &stream, DateOrError *tmp)
{
    std::string line;

    getline(stream, line);
    if(line[0] != '|' || line[1] != ' ')
    {
        tmp->error = "Error format needs to be: date | value: \" not "  + line + "\"";
        return ;
    }
    line.erase(0, 2);
    stream.clear();
    stream.str(line);
    if(strToNumeric( stream, tmp->ammount, tmp->f_ammount ) == true)
        return ;
    tmp->error = "Error just Int or Float: \""  + line + "\"";
}

void BitcoinExchange::save_line( std::string line )
{
    DateOrError tmp;
    std::string date;
    std::stringstream stream(line);
    std::stringstream stream_YYYY_MM_DD(line);
    
    getline(stream_YYYY_MM_DD, date, '|');
    if(dateInRange(stream, tmp.year, '-', 2009, 2022) == false)
        tmp.error = "Error bad input: \""  + date + "\"";
    else if(dateInRange(stream, tmp.month, '-', 1, 12) == false)
        tmp.error = "Error bad input: \""  + date + "\"";
    else if(dateInRange(stream, tmp.day, ' ', 1, 32) == false)
        tmp.error = "Error bad input: \""  + date + "\"";
    else
        vaildValue( stream, &tmp);
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
