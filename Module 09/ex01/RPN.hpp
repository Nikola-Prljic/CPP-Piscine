#ifndef RPN_HPP
# define RPN_HPP

# define RPN_Error 1

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <cstdlib>

class RPN
{
private:
    const std::string _inputStr;
    std::queue<int> _queueNum;
    std::queue<int> _queueOpr;

    RPN();
    int saveInput();
    int saveNumberLoop( size_t &i );
    int saveOperatorLoop( size_t &i );
    int clearStacks_calc();
    int doCalc(int n1, int n2, int sign);
    int saveToStack( std::queue<int> &queue, int c, int (*func)( int ));
    void reverseNumQuene( std::queue<int> &Queue );

public:
    RPN( const std::string inputStr );
    RPN( const RPN &other );
    ~RPN();

    RPN &operator=( const RPN &other );
    int getResult();
};

#endif
