#include "ScalarConverter.hpp"

std::string ScalarConverter::_input = "0";

char ScalarConverter::_char = '0';

int ScalarConverter::_int = 0;

float ScalarConverter::_float = 0;

double ScalarConverter::_double = 0;

long double ScalarConverter::_ld = 0;

e_type ScalarConverter::_type = NONE;

std::string ScalarConverter::error_msg[4];

ScalarConverter::ScalarConverter( std::string input ) 
{ 
    _input = input;
    convert(_input); 
}

ScalarConverter::ScalarConverter( ScalarConverter & rhs )
{
    _input = rhs._input;
    _char = rhs._char;
    _int = rhs._int;
    _float = rhs._float;
    _double = rhs._double;
    _ld = rhs._ld;
    _type =rhs._type;
    for(int i = 0; i < 4; i++)
        error_msg[i] = rhs.error_msg[i];
    return ;
}

ScalarConverter& ScalarConverter::operator=( ScalarConverter tmp )
{
    std::swap( _input, tmp._input );
    std::swap( _input, tmp._input );
    std::swap( _char, tmp._char );
    std::swap( _int, tmp._int );
    std::swap( _float, tmp._float );
    std::swap( _double, tmp._double );
    std::swap( _ld, tmp._ld );
    std::swap( _type, tmp._type );
    for(int i = 0; i < 4; i++)
        std::swap(error_msg[i], tmp.error_msg[i]);
    return *this;
}

void ScalarConverter::toChar( int c )
{
    if( c > '~' || c < ' ')
        error_msg[0] = "Is not printable";
    _char = (char)c;
    return ;
}

void ScalarConverter::toFloatOrDuble()
{
    float   f;

    std::istringstream ss(_input);
    if(ss >> f)
    {
        _type = FLOAT;
        _float = f;
        return ;
    }
    error_msg[1] = "overflow";
    error_msg[2] = "overflow";
    error_msg[3] = "overflow";
}

bool ScalarConverter::toDouble()
{
    long double x;

    std::istringstream ss(_input);
    if(ss >> x )
    {
        if(x > -1 && x <= std::numeric_limits<double>::max() && x >= std::numeric_limits<double>::min())
        {
            _double = static_cast<double>(x);
            return true;
        }
        if(x < 0 && x >= -std::numeric_limits<double>::max() && x <= -std::numeric_limits<double>::min())
        {
            _double = static_cast<double>(x);
            return true;
        }
    }
    for(int i = 1; i < 4; i++)
        error_msg[i] = "overflow";
    return false;
}

void ScalarConverter::isBiggerFloat()
{
    _ld = (long double)_double;
    if( _ld > INT_MAX || _ld < INT_MIN)
        error_msg[1] = "overflow";
    if( _ld > -1 && (_ld > std::numeric_limits<float>::max() || _ld < std::numeric_limits<float>::min() ) )
        error_msg[2] = "overflow";
    else if( _ld < 0 && (_ld > -std::numeric_limits<float>::max() || _ld < -std::numeric_limits<float>::min() ) )
        error_msg[2] = "overflow";
}

void ScalarConverter::covert_from_int()
{
    _type = INT;
    long long num = 0;

    if( _input == "0" || _input == "-1")
    {
        _int = atol(_input.c_str());
        toChar(_int);
        _float = static_cast<float>(_int);
        _double = static_cast<double>(_int);
        return ;
    }
    num = atol(_input.c_str());
    if( num > INT_MAX || num < INT_MIN || num == -1 || num == 0)
    {
        error_msg[0] = "overflow";
        error_msg[1] = "overflow";
        error_msg[2] = "overflow";
        error_msg[3] = "overflow";
    }
    else
    {
        _int = num;
        toChar(_int);
        _float = static_cast<float>(_int);
        _double = static_cast<double>(_int);
    }
}

void ScalarConverter::covert_from_char()
{
    _type = CHAR;
    toChar(_char);
    _int = (int)_char;
    _float = (float)_char;
    _double = (double)_char;
    return ;
}

void ScalarConverter::covert_from_float()
{
    toFloatOrDuble();
    toChar(_float);
    _int = static_cast<int>(_float);
    _double = static_cast<double>(_float);
    isBiggerFloat();
}


void ScalarConverter::covert_from_double()
{
    toDouble();
    toChar(_double);
    _int = static_cast<int>(_double);
    _float = static_cast<float>(_double);
    isBiggerFloat();
}

void ScalarConverter::convert( std::string input )
{
    for(int i = 0; i < 4; i++)
        error_msg[i] = "";
    _input = input;
    if(isPseudoLiterals() != "0")
        setPseudoLiterals();
    if(isInt() == true)
        covert_from_int();
    else if(isChar() == true)
        covert_from_char();
    else if(isFloat() == true)
        covert_from_float();
    else if(isDouble() == true)
        covert_from_double();
    else
    {
        for(int i = 0; i < 4; i++)
            error_msg[i] = "Not possible";
    }
    return ;
}

bool ScalarConverter::isInt()
{
    int i = 0;
    /* long long num; */

    /* if( _input == "0" || _input == "-1")
        return true; */
    if(_input[0] == '-')
        i = 1;
    for(; _input[i]; i++)
        if (isdigit(_input[i]) == 0)
            return false;
    /* num = std::atol( _input.c_str() ); */
    /* if( num > INT_MAX || num < INT_MIN )
        return false; */
    /* if(num != 0 && num != -1)
        return true; */
    return true;
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
    int i = 0;
    int dot = 0;
    int len = 0;

    if(_input[_input.size() - 1] != 'f')
        return false;
    len = _input.size() - 1;
    if(_input[0] == '-')
        i = 1;
    for(; i < len ; i++)
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
    int i = 0;
    int dot = 0;

    if(_input[0] == '-')
        i = 1;
    for(; _input[i]; i++)
    {
        if (isdigit(_input[i]) == 0)
        {
            if (_input[i] == '.' && i != 0 && dot == 0)
                dot++;
            else
                return false;
            if(_input[i] == '.' && _input[i + 1] == '\0')
                return false;
        }
    }
    return true;
}

std::string ScalarConverter::isPseudoLiterals()
{
    if ( ( _input ==  "nan" ) || ( _input ==  "nanf" )
        || ( _input ==  "+inf" ) || ( _input ==  "+inff" )
        || ( _input ==  "-inf" ) || ( _input ==  "-inff" ))
        return _input;
    return "0";
}

void ScalarConverter::setPseudoLiterals()
{
    error_msg[0] = "Not possible";
    error_msg[1] = "Not possible";
    if(_input == "nan" || _input ==  "+inf" || _input ==  "-inf")
    {
        error_msg[2] = isPseudoLiterals() + "f";
        error_msg[3] = isPseudoLiterals();
    }
    else
    {
        error_msg[2] = isPseudoLiterals();
        std::string tmp = isPseudoLiterals();
        tmp.erase(tmp.end() - 1);
        error_msg[3] = tmp;
    }
    return ;
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
    if(str[i] == 'f' && str[i + 1] == '\0')
        return true;
    if(str[i] == '\0')
        return true;
    return false;
}

bool MoreThanSixDigis( std::string input )
{
    int i = 0;

    while(input[i] && input[i] != '.')
        i++;
    if(i > 6)
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
            if(MoreThanSixDigis(sc.getInput()) == false)
            {
                if( ( sc.getType() == INT || sc.getType() == CHAR || floatIsJustNull( sc.getInput() ) ))
                    os << ".0";
                os << "f";
            }
        }
        else if ( choseTypeMsg == "double")
        {
            os << sc.getDouble();
            if(( sc.getType() == INT || sc.getType() == CHAR || floatIsJustNull( sc.getInput() ) ) && MoreThanSixDigis(sc.getInput()) == false )
                os << ".0";
        }
    }
    else
        os << sc.getErrorMsg( choseTypeMsg );
}

std::string ScalarConverter::getErrorMsg( std::string error_type_msg ) 
{ 
    if( error_type_msg == "char")
        return error_msg[0];
    if( error_type_msg == "int")
        return error_msg[1];
    if( error_type_msg == "float")
        return error_msg[2];
    if( error_type_msg == "double")
        return error_msg[3];
    return "!! -> Error: msg not found !!";
}


std::ostream& operator<<( std::ostream& os, ScalarConverter& sc )
{
    printErrorMsg( os, sc, "char" );
    os << std::endl;
    printErrorMsg( os, sc, "int" );
    os << std::endl;
    printErrorMsg( os, sc, "float" );
    os << std::endl;
    printErrorMsg( os, sc, "double" );
    return os;
}