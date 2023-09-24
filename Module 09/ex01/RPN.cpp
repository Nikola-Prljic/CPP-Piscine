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

RPN::RPN( const std::string inputStr ) : _inputStr(inputStr), _queueNum(), _queueOpr()
{
    if(_inputStr.empty() == true)
        std::cerr << "Error input empty" << std::endl;
    else if(_inputStr.size() < 5)
        std::cerr << "Error try input like: 8 6 *" << std::endl;
    else if(!saveInput())
        std::cout << _queueNum.front() << std::endl;
}

RPN::RPN( const RPN &other ) : _inputStr(other._inputStr), _queueNum(other._queueNum), _queueOpr(other._queueOpr) {}

RPN::~RPN() {}

RPN &RPN::operator=( const RPN &other )
{
    if(this != &other)
    {
        _queueNum = other._queueNum;
        _queueOpr = other._queueOpr;
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
        if(saveToStack( _queueNum, _inputStr[i++], &ft_isdigit))
            return RPN_Error;
        if(_inputStr[i] == 0 || _inputStr[i++] != ' ')
        {
            std::cerr << "Error bad input" << std::endl;
            return RPN_Error;
        }
        if(std::isdigit(_inputStr[i]) == false)
            break ;
    }
    reverseNumQuene( _queueNum );
    return 0;
}

int RPN::saveOperatorLoop( size_t &i )
{
    while(i < _inputStr.size())
    {
        if(saveToStack( _queueOpr, _inputStr[i++], &ft_isOperator))
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

    if(_queueNum.size() < 2 || _queueNum.size() - 1 != _queueOpr.size())
    {
        std::cerr << "Error ammount of Numbers and operators are wrong" << std::endl;
        return RPN_Error;
    }
    while(_queueNum.size() > 1)
    {
        n2 = _queueNum.front();
        _queueNum.pop();
        _queueNum.front() = doCalc( _queueNum.front(), n2, _queueOpr.front());
        _queueOpr.pop();
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


int RPN::saveToStack( std::queue<int> &queue, int c, int (*func)( int ))
{
    if(func(c))
    {
        if(!ft_isOperator( c ))
            c -= '0';
        queue.push( c );
        return 0;
    }
    std::cerr << "Error bad input" << std::endl;
    return RPN_Error;
}

int RPN::getResult() { return _queueNum.front(); }

void RPN::reverseNumQuene( std::queue<int> &Quene )
{
    if (Quene.size() == 0)
        return;
    int fr = Quene.front();
    Quene.pop();
    reverseNumQuene(Quene);
    Quene.push(fr);
}