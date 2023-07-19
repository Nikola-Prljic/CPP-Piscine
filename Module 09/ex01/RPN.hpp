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
    const std::string _inputStr;
    std::list<int> _listNum;
    std::list<int> _listOpr;
    int result;

    RPN();
    void calc();
    void saveInput();
    int saveToStack( std::list<int> &list, int c, int (*func)( int ));

public:
    RPN( std::string inputStr );
    ~RPN();

    int getResult();
};

#endif