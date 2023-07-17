#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <list>
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
    std::list<int> _calc;
    RPN();

public:
    RPN( std::string inputStr);
    ~RPN();
    void validInput();
    void calc();
};

#endif