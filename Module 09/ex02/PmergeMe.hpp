#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include "vector"
#include <iostream>

class PmergeMe
{
private:
    typedef std::vector<int> vectorInt;
    vectorInt _vector;

    PmergeMe();
    
public:
    PmergeMe( vectorInt input );
    ~PmergeMe();
    void printVector();
};

#endif