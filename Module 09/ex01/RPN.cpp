#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN( std::string inputStr ) : _inputStr(inputStr), _listNum(), _listOpr()
{
    validInput();
    std::cout << result << std::endl;
    /* std::cout << "--ok--" << std::endl; */
}

RPN::~RPN() {}

bool ft_isOperator( char c)
{
    std::string opr = "+-*/";
    for(size_t i = 0; i < opr.size(); i++)
        if(c == opr[i])
            return true;
    return false;
}

int doCalc(int n1, int n2, int sign)
{
    if(sign == '+')
        return n1 + n2;
    if(sign == '-')
        return n1 - n2;
    if(sign == '/')
        return n1 / n2;
    if(sign == '*')
        return n1 * n2;
    std::cout << "Error at doCalc no valid sign: " << sign << std::endl;
    return sign;
}

int doCalc(int n1, int n2, int n3, int sign1, int sign2)
{
    int result = doCalc(n1, n2, sign1);
    return doCalc(result, n3, sign2);
}

void RPN::calc()
{
    int opr1, opr2;
    int result, n3;

    opr1 = _listNum.back();
    _listNum.pop_back();
    if(_listNum.back() > 9)
    {
        opr2 = opr1;
        opr1 = _listNum.back();
        _listNum.pop_back();
        n3 = _listNum.back();
        _listNum.pop_back();
        result = doCalc(_listNum.front(), _listNum.back(), n3, opr1, opr2);
        _listNum.clear();
        _listNum.push_back(result);
        return ;
    }
    result = doCalc(_listNum.front(), _listNum.back(), opr1);
    _listNum.clear();
    _listNum.push_back(result);
}


/* void RPN::firstInput(std::stringstream &inputstream)
{
    std::string tmp;
    getline(inputstream, tmp, ' ');
    if(std::isdigit(tmp[0]) == false || tmp.size() != 1)
        return exit(1);
    _listNum.push_back(tmp[0] - '0');
    getline(inputstream, tmp, ' ');
    if(std::isdigit(tmp[0]) == false || tmp.size() != 1)
        return exit(1);
    _listNum.push_back(tmp[0] - '0');
    ft_saveOperator( inputstream );
} */


bool ft_isEofSS(std::stringstream &inputstream, std::string &tmp)
{
    getline(inputstream, tmp, ' ');
    if( inputstream.eof() == true )
        return true;
    return false;
}

bool RPN::ft_saveOperator( char c )
{
    if(ft_isOperator(c) == true)
    {
        _listOpr.push_back( c );
        std::cout << (char)c << std::endl;
        return true;
    }
    else
        std::exit(1);
    return false;
}

void RPN::ft_saveDigit( bool first, const char c )
{
    if(std::isdigit(c) == true)
    {
        if( first == true)
            result = c - '0';
        else
        {
            _listNum.push_back( c - '0' );
            std::cout << c - '0' << std::endl;
        }
    }
    else 
        return std::exit(1);
}

void RPN::validInput()
{
    int i = 2;

    ft_saveDigit( true, _inputStr[0] );
    while(_inputStr[i])
    {
        ft_saveDigit( false, _inputStr[i++] );
        if(_inputStr[i++] != ' ')
            std::exit(1);
        if(isdigit(_inputStr[i]) == false)
            break ;
    }
    while(_inputStr[i])
    {
        ft_saveOperator( _inputStr[i++] );
        if(_inputStr[i++] != ' ')
            std::exit(1);
    }
    //calc();
}
