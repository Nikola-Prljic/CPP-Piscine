#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <float.h>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( std::string input ) : _input(input), _char(0), _int(0), _type(NONE)
{
    return ;
}

void ScalarConverter::toChar( int c )
{
    if( c > '~' || c < ' ')
        std::cout << "Is not printable" << std::endl;
    else
        std::cout << (char)c << std::endl;
    return ;
}

void ScalarConverter::toInt()
{
    _int = std::atoi( _input.c_str() );
    std::cout << _int << std::endl;
    return ;
}

void ScalarConverter::covert_from_int()
{
    toInt();
    toChar(_int);
    _char = _int;
    _float = _int;
    std::cout << _float << std::endl;
    return ;
}

void ScalarConverter::covert_from_char()
{
    toChar(_char);
    _int = _char;
    std::cout << _int << std::endl;
    return ;
}

void ScalarConverter::covert_from_float()
{
    toFloat();
    return ;
}

void ScalarConverter::convert_switch()
{
    switch(_type)
    {
        case INT:
            covert_from_int();
            std::cout << "INT" << std::endl; break ;
        case CHAR:
            covert_from_char();
            std::cout << "CHAR" << std::endl; break ;
        case FLOAT:
            toFloat();
            std::cout << "FLOAT" << std::endl; break ;
        default:
            std::cout << "error" << std::endl; break ;
    }
    return ;
}

void ScalarConverter::convert()
{
    if(isInt() == true)
        _type = INT;
    else if(isChar() == true)
        _type = CHAR;
    else if(isFloat() == true)
        _type = FLOAT;
    convert_switch();
    return ;
}

bool ScalarConverter::isInt()
{
    long long i;

    if( _input == "0" || _input == "-1")
        return true;
    for(int i = 0; _input[i]; i++)
        if (isdigit(_input[i]) == 0)
            return false;
    i = std::atol( _input.c_str() );
    if( i > INT_MAX || i < INT_MIN )
        return false;
    if(i != 0 && i != -1)
        return true;
    return false;
}

bool ScalarConverter::isChar()
{
    if( _input.size() != 1)
        return false;
    if( isprint( (int)_input[0] ) != 0 )
    {
        _char = _input[0];
        return true;
    }
    return false;
}

bool ScalarConverter::isFloat()
{
    int dot = 0;

    if(_input.back() != 'f')
        return false;
    _input.pop_back();
    for(int i = 0; _input[i]; i++)
    {
        if (isdigit(_input[i]) == 0)
        {
            if (_input[i] == '.' && i != 0 && dot == 0)
                dot++;
            else
                return false;
        }
    }
    return true;
}

void ScalarConverter::toFloat()
{
    float x;

    std::istringstream ss(_input);
    if(ss >> x)
    {
        std::cout << x << std::endl;
        _float = x;
    }
    else
        std::cout << "overflow" << std::endl;
    return ;
}

/* std::ostream& operator<<(std::ostream& os, const ScalarConverter& sc)
{
    os << sc._char << 
    return ;
} */