#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN( const std::string inputStr ) : _inputStr(inputStr), _listNum(), _listOpr(), result(69)
{
    if(_inputStr.empty() == true)
        std::cerr << "Error input empty" << std::endl;
    else if(_inputStr.size() < 5)
        std::cerr << "Error try input like: 8 6 *" << std::endl;
    else if(!saveInput())
        std::cout << result << std::endl;
}

RPN::RPN( const RPN &other ) : _inputStr(other._inputStr), _listNum(other._listNum), _listOpr(other._listOpr), result(other.result) {}

RPN::~RPN() {}

RPN &RPN::operator=( const RPN &other )
{
    if(this != &other)
    {
        _listNum = other._listNum;
        _listOpr = other._listOpr;
        result = other.result;
    }
    return *this;
}

int RPN::getResult() { return result; }

int ft_isOperator( int c)
{
    std::string opr = "+-*/";
    for(size_t i = 0; i < opr.size(); i++)
        if(c == opr[i])
            return 1;
    return 0;
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

int RPN::clearStacks_calc( bool first )
{
    if(_listNum.size() != _listOpr.size())
    {
        std::cerr << "Error ammount of Numbers and operators are wrong" << std::endl;
        return RPN_Error;
    }
    while(_listNum.empty() == false)
    {
        if( first == true )
            result = doCalc( _listNum.back(), result, _listOpr.front());
        else
        {
            std::cout << result << (char)_listOpr.front() << _listNum.back() << " = ";
            result = doCalc( result, _listNum.back(), _listOpr.front());
            std::cout << result << std::endl;
        }
        _listNum.pop_back();
        _listOpr.pop_front();
    }
    return 0;
}

int ft_isdigit(int n)
{
    if(n < 48 || n > 57)
        return 0;
    return 1;
}

int RPN::saveToStack( std::list<int> &list, int c, int (*func)( int ))
{
    if(func(c))
    {
        if(!ft_isOperator( c ))
            c -= '0';
        list.push_back( c );
        return 0;
    }
    std::cerr << "Error bad input" << std::endl;
    return RPN_Error;
}

int RPN::saveOperatorLoop( size_t &i )
{
    while(i < _inputStr.size())
    {
        if(saveToStack( _listOpr, _inputStr[i++], &ft_isOperator))
            return RPN_Error;
        if(_inputStr[i] != 0 && _inputStr[i++] != ' ')
        {
            std::cerr << "Error bad input" << std::endl;
            return RPN_Error;
        }
        if(ft_isdigit(_inputStr[i]))
            return 0;
    }
    return 0;
}


int RPN::saveNumberLoop( size_t &i )
{
    while(i < _inputStr.size())
    {
        if(saveToStack( _listNum, _inputStr[i++], &ft_isdigit))
            return RPN_Error;
        if(_inputStr[i] == 0 || _inputStr[i++] != ' ')
        {
            std::cerr << "Error bad input" << std::endl;
            return RPN_Error;
        }
        if(std::isdigit(_inputStr[i]) == false)
            break ;
    }
    return 0;
}

int RPN::saveFistLine( size_t &i )
{
    if(saveNumberLoop(i))
        return RPN_Error;
    result = _listNum.back();
    _listNum.pop_back();
    if( saveOperatorLoop(i) || clearStacks_calc( true ) )
        return RPN_Error;
    return 0;
}

int RPN::saveInput()
{
    size_t i = 0;

    if(!std::isdigit(_inputStr[0]) || _inputStr[1] != ' ')
    {
        std::cerr << "Error bad input" << std::endl;
        return RPN_Error;
    }
    if(saveFistLine(i))
        return RPN_Error;
    while(_inputStr[i])
        if( saveNumberLoop(i) || saveOperatorLoop(i) || clearStacks_calc( false ) )
            return RPN_Error;
    return 0;
}
