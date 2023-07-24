#include "RPN.hpp"

int ft_isdigit(int n)
{
    if(n < 48 || n > 57)
        return 0;
    return 1;
}

int ft_isOperator( int c)
{
    std::string opr = "+-*/";
    for(size_t i = 0; i < opr.size(); i++)
        if(c == opr[i])
            return 1;
    return 0;
}

RPN::RPN() {}

RPN::RPN( const std::string inputStr ) : _inputStr(inputStr), _listNum(), _listOpr()
{
    if(_inputStr.empty() == true)
        std::cerr << "Error input empty" << std::endl;
    else if(_inputStr.size() < 5)
        std::cerr << "Error try input like: 8 6 *" << std::endl;
    else if(!saveInput())
        std::cout << _listNum.front() << std::endl;
}

RPN::RPN( const RPN &other ) : _inputStr(other._inputStr), _listNum(other._listNum), _listOpr(other._listOpr) {}

RPN::~RPN() {}

RPN &RPN::operator=( const RPN &other )
{
    if(this != &other)
    {
        _listNum = other._listNum;
        _listOpr = other._listOpr;
    }
    return *this;
}

int RPN::saveInput()
{
    size_t i = 0;

    if(!std::isdigit(_inputStr[0]) || _inputStr[1] != ' ')
    {
        std::cerr << "Error bad input" << std::endl;
        return RPN_Error;
    }
    while(_inputStr[i])
        if( saveNumberLoop(i) || saveOperatorLoop(i) || clearStacks_calc() )
            return RPN_Error;
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

int RPN::clearStacks_calc()
{
    int n2;

    if(_listNum.size() < 2 || _listNum.size() - 1 != _listOpr.size())
    {
        std::cerr << "Error ammount of Numbers and operators are wrong" << std::endl;
        return RPN_Error;
    }
    while(_listNum.size() > 1)
    {
        n2 = _listNum.back();
        _listNum.pop_back();
        _listNum.back() = doCalc( _listNum.back(), n2, _listOpr.front());
        _listOpr.pop_front();
    }
    return 0;
}

int RPN::doCalc(int n1, int n2, int sign)
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

int RPN::getResult() { return _listNum.front(); }
