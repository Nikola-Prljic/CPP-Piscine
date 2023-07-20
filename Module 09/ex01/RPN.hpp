#ifndef RPN_HPP
# define RPN_HPP

# define RPN_Error 1

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <cstdlib>

class RPN
{
private:
    const std::string _inputStr;
    std::list<int> _listNum;
    std::list<int> _listOpr;
    int result;

    RPN();
    int clearStacks_calc();
    int saveInput();
    int saveOperatorLoop( size_t &i );
    int saveNumberLoop( size_t &i );
    int saveToStack( std::list<int> &list, int c, int (*func)( int ));

public:
    RPN( std::string inputStr );
    ~RPN();

    int getResult();
};

#endif