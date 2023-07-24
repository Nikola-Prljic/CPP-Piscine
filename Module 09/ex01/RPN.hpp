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

    RPN();
    int saveInput();
    int saveNumberLoop( size_t &i );
    int saveOperatorLoop( size_t &i );
    int clearStacks_calc();
    int doCalc(int n1, int n2, int sign);
    int saveToStack( std::list<int> &list, int c, int (*func)( int ));

public:
    RPN( const std::string inputStr );
    RPN( const RPN &other );
    ~RPN();

    RPN &operator=( const RPN &other );
    int getResult();
};

#endif
