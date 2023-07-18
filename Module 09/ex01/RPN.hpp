#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>

class RPN
{
private:
    struct data{
        int n1;
        int n2;
        char opr1;
        char opr2;
    };
    std::string _inputStr;
    std::map<int, int> _stack;
    int result;
    RPN();

public:
    RPN( std::string inputStr);
    ~RPN();
    void firstInput( std::stringstream &inputstream );
    void validInput();
    void calc();
    void ft_saveOperator( std::stringstream &inputstream );
    void ft_saveDigit( bool first, const std::string &tmp );
};

#endif