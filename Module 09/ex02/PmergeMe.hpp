#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include "vector"

class PmergeMe
{
private:
    std::vector<int> _vector;

    PmergeMe();
    
public:
    PmergeMe( char **argv );
};

#endif