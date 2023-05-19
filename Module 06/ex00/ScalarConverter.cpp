#include "ScalarConverter.hpp"
#include <cctype>

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
    return ;
}

void ScalarConverter::covert_from_char()
{
    toChar(_char);
    _int = _char;
    std::cout << _int << std::endl;
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
    convert_switch();
    return ;
}

bool ScalarConverter::isInt()
{
    long long i;

    if( _input == "0" || _input == "-1")
        return true;
    i = std::atol( _input.c_str() );
    if( i > 2147483647)
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