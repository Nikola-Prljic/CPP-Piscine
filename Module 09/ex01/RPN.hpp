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
    std::list<int> _listNum;
    std::list<int> _listOpr;
    int result;
    RPN();

public:
    RPN( std::string inputStr);
    ~RPN();
    /* void firstInput( std::stringstream &inputstream ); */
    void validInput();
    void calc();
    bool ft_saveOperator( char c );
    void ft_saveDigit( bool first, const char c );
};

#endif