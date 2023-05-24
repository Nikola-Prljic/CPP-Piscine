#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( std::string input ) : _input(input), _char('0'), _int(0), _float(0), _double(0), _type(NONE), error_msg()
{
    for(int i = 0; i < 4; i++)
        error_msg[i] = "";
    return ;
}

void ScalarConverter::toChar( int c )
{
    if( c > '~' || c < ' ')
        error_msg[0] = "Is not printable";
    _char = (char)c;
    return ;
}

void ScalarConverter::toInt()
{
    _int = std::atoi( _input.c_str() );
    std::cout << _int << std::endl;
    return ;
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
        error_msg[2] = "overflow";
    return ;
}

void ScalarConverter::toDouble()
{
    double x;

    std::istringstream ss(_input);
    if(ss >> x)
    {
        std::cout << x << std::endl;
        _double = x;
    }
    else
        error_msg[3] = "overflow";
    return ;
}

void ScalarConverter::covert_from_int()
{
    toInt();
    toChar(_int);
    _float = _int;
    _double = _int;
    return ;
}

void ScalarConverter::covert_from_char()
{
    toChar(_char);
    _int = _char;
    _float = _char;
    _double = _char;
    return ;
}

void ScalarConverter::covert_from_float()
{
    toFloat();
    toChar(_float);
    _int = _float;
    _double = _float;
    return ;
}

void ScalarConverter::covert_from_double()
{
    toDouble();
    toChar(_double);
    _int = _double;
    _float = _double;
    return ;
}

/* void ScalarConverter::convert_switch()
{
    switch(_type)
    {
        case INT:
            covert_from_int(); break ;
        case CHAR:
            covert_from_char(); break ;
        case FLOAT:
            covert_from_float(); break ;
        case DOUBLE:
            covert_from_double(); break ;
        default:
            std::cout << "error" << std::endl; break ;
    }
    return ;
} */

void ScalarConverter::convert()
{
    if(isInt() == true)
        covert_from_int();
    else if(isChar() == true)
        covert_from_char();
    else if(isFloat() == true)
        covert_from_float();
    else if(isDouble() == true)
        covert_from_double();
    //convert_switch();
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
    int len = 0;

    if(_input.back() != 'f')
        return false;
    len = _input.size() - 1;
    for(int i = 0; i < len ; i++)
    {
        if (isdigit(_input[i]) == 0)
        {
            if (_input[i] == '.' && i != 0 && dot == 0)
                dot++;
            else
                return false;
            if(_input[i] == '.' && _input[i + 1] == 'f')
                return false;
        }
    }
    if(dot == 0)
        return false;
    return true;
}

bool ScalarConverter::isDouble()
{
    int dot = 0;

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

int ScalarConverter::getInt() { return _int; }

char ScalarConverter::getChar() { return _char; }

float ScalarConverter::getFloat() { return _float; }

double ScalarConverter::getDouble() { return _double; }

std::string ScalarConverter::getInput() { return _input; }

e_type ScalarConverter::getType() { return _type; }

bool floatIsJustNull( std::string str )
{
    int i = str.find('.');
    i++;
    while(str[i] == '0')
        i++;
    if(str[i] == 'f')
        return true;
    return false;
}

void printErrorMsg( std::ostream& os, ScalarConverter& sc, std::string choseTypeMsg )
{
    os << choseTypeMsg << " : ";
    if(sc.getErrorMsg( choseTypeMsg ) == "" )
    {
        if (choseTypeMsg == "char")
            os << sc.getChar();
        else if ( choseTypeMsg == "int" )
            os << sc.getInt();
        else if ( choseTypeMsg == "float")
        {
            os << sc.getFloat(); 
            if(sc.getType() == INT || sc.getType() == CHAR || floatIsJustNull( sc.getInput() ))
                os << ".0";
            os << "f";
        }
        else if ( choseTypeMsg == "double")
            os << sc.getDouble();
    }
    else
        os << sc.getErrorMsg( choseTypeMsg );
    os << std::endl;
    return;
}

std::string ScalarConverter::getErrorMsg( std::string error_type_msg ) 
{ 
    if( error_type_msg == "char")
        return this->error_msg[0];
    if( error_type_msg == "int")
        return this->error_msg[1];
    if( error_type_msg == "float")
        return this->error_msg[2];
    if( error_type_msg == "double")
        return this->error_msg[3];
    return "!! -> Error: msg not found !!";
}

std::ostream& operator<<( std::ostream& os, ScalarConverter& sc )
{
    printErrorMsg( os, sc, "char" );
    printErrorMsg( os, sc, "int" );
    printErrorMsg( os, sc, "float" );
    printErrorMsg( os, sc, "double" );
    return os;
}