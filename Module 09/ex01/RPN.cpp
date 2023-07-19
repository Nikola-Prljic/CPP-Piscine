#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN( std::string inputStr ) : _inputStr(inputStr), _listNum(), _listOpr()
{
    
    validInput();
    std::cout << "sum = " << result << std::endl;
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

void RPN::calc()
{
    while(_listNum.empty() == false)
    {
        result = doCalc(result, _listNum.back(), _listOpr.back());
        _listNum.pop_back();
        _listOpr.pop_back();
    }
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
        std::exit(3);
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
        return std::exit(2);
}

void RPN::validInput()
{
    size_t i = 2;

    ft_saveDigit( true, _inputStr[0] );
    while(_inputStr[i])
    {
        while(i < _inputStr.size())
        {
            ft_saveDigit( false, _inputStr[i++] );
            if(_inputStr[i] == 0 || _inputStr[i++] != ' ')
                return ;
            if(isdigit(_inputStr[i]) == false)
                break ;
        }
        while(i < _inputStr.size())
        {
            ft_saveOperator( _inputStr[i++] );
            if(_inputStr[i] != 0 && _inputStr[i++] != ' ')
                return ;
            if(isdigit(_inputStr[i]) == true)
                break ;
        }
        calc();
    }
}
