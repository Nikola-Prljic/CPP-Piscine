#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN( std::string inputStr ) : _inputStr(inputStr), _calc()
{
    validInput();
    std::cout << _calc.front() << std::endl;
    std::cout << "--ok--" << std::endl;
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
        _calc.clear();
        _calc.push_back(result);
        return ;
    }
    result = doCalc(_calc.front(), _calc.back(), opr1);
    _calc.clear();
    _calc.push_back(result);
}

void RPN::ft_saveOperator( std::stringstream &inputstream )
{
    std::string tmp;
    getline(inputstream, tmp, ' ');
    if(ft_isOperator(tmp[0]) == true && tmp.size() == 1)
        _calc.push_back(tmp[0]);
    else
        return std::exit(1);
}

void RPN::firstInput(std::stringstream &inputstream)
{
    std::string tmp;
    getline(inputstream, tmp, ' ');
    if(std::isdigit(tmp[0]) == false || tmp.size() != 1)
        return exit(1);
    _calc.push_back(tmp[0] - '0');
    getline(inputstream, tmp, ' ');
    if(std::isdigit(tmp[0]) == false || tmp.size() != 1)
        return exit(1);
    _calc.push_back(tmp[0] - '0');
    ft_saveOperator( inputstream );
}

bool ft_isEofSS(std::stringstream &inputstream, std::string &tmp)
{
    getline(inputstream, tmp, ' ');
    if( inputstream.eof() == true )
        return true;
    return false;
}

void RPN::validInput()
{
    std::string tmp;
    std::stringstream inputstream(_inputStr);
    firstInput( inputstream );
    calc();

    while(ft_isEofSS( inputstream, tmp) == false)
    {
        if(std::isdigit(tmp[0]) == true && tmp.size() == 1)
            _calc.push_back(tmp[0] - '0');
        else
            return std::exit(1);
        getline(inputstream, tmp, ' ');
        if(ft_isOperator(tmp[0]) == true && tmp.size() == 1)
            _calc.push_back(tmp[0]);
        else if(std::isdigit(tmp[0]) == true && tmp.size() == 1)
        {
            _calc.push_back(tmp[0] - '0');
            ft_saveOperator( inputstream );
            ft_saveOperator( inputstream );
        }
        else
            return std::exit(1);
        calc();
    }
}
