#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN( std::string inputStr ) : _inputStr(inputStr), _calc()
{
    validInput();
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
    char opr1, opr2;
    int result, n3;

    opr1 = _calc.back();
    _calc.pop_back();
    if(_calc.back() > 9)
    {
        opr2 = opr1;
        opr1 = _calc.back();
        _calc.pop_back();
        n3 = _calc.back();
        _calc.pop_back();
        result = doCalc(_calc.front(), _calc.back(), n3, opr1, opr2);
        std::cout << _calc.front() << std::endl;
        return ;
    }
    result = doCalc(_calc.front(), _calc.back(), opr1);
    _calc.clear();
    _calc.push_back(result);
    std::cout << _calc.front() << std::endl;
}

void RPN::validInput()
{
    std::string tmp;
    std::stringstream inputstream(_inputStr);

    getline(inputstream, tmp, ' ');
    if(std::isdigit(tmp[0]) == false || tmp.size() != 1)
        return exit(1);
    _calc.push_back(tmp[0] - '0');
    getline(inputstream, tmp, ' ');
    if(std::isdigit(tmp[0]) == false || tmp.size() != 1)
        return exit(1);
    _calc.push_back(tmp[0] - '0');
    getline(inputstream, tmp, ' ');
    if(ft_isOperator(tmp[0]) == false || tmp.size() != 1)
        return exit(1);
    _calc.push_back(tmp[0]);
    calc();
    std::cout << "--ok--" << std::endl;
}
