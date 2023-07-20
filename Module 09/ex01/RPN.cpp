#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN( std::string inputStr ) : _inputStr(inputStr), _listNum(), _listOpr(), result(69)
{
    if(_inputStr.empty() == true)
        std::cerr << "Error input empty" << std::endl;
    else if(_inputStr.size() == 1)
        std::cout << "Try input like \"8 6 *\"" << std::endl;
    else 
        saveInput();
}

int RPN::getResult() { return result; }

RPN::~RPN() {}

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

int RPN::clearStacks_calc()
{
    if(_listNum.size() != _listOpr.size())
    {
        std::cerr << "Error ammount of Numbers and operators are wrong" << std::endl;
        return 1;
    }
    while(_listNum.empty() == false)
    {
        result = doCalc(result, _listNum.back(), _listOpr.back());
        _listNum.pop_back();
        _listOpr.pop_back();
    }
    return 0;
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
    std::cerr << "Error bad input : " << (char)c << std::endl;
    return 1;
}

int RPN::saveOperatorLoop( size_t &i )
{
    while(i < _inputStr.size())
    {
        if(saveToStack( _listOpr, _inputStr[i++], &ft_isOperator))
            return 1;
        if(_inputStr[i] != 0 && _inputStr[i++] != ' ')
            return 1;
        if(std::isdigit(_inputStr[i]) == true)
            return 0;
    }
    return 0;
}

void RPN::saveInput()
{
    if(!std::isdigit(_inputStr[0]))
    {
        std::cerr << "Error bad input : " << _inputStr << std::endl;
        return ;
    }
    result = _inputStr[0] - '0';
    for(size_t i = 2; _inputStr[i];)
    {
        while(i < _inputStr.size())
        {
            if(saveToStack( _listNum, _inputStr[i++], &isdigit))
                return ;
            if(_inputStr[i] == 0 || _inputStr[i++] != ' ')
                return ;
            if(std::isdigit(_inputStr[i]) == false)
                break ;
        }
        if(saveOperatorLoop(i) || clearStacks_calc())
            return ;
    }
}
