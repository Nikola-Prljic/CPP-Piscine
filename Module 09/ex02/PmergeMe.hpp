#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include "vector"
#include <iostream>

class PmergeMe
{    

private:
    typedef std::vector<int> vectorInt;
    typedef std::vector<int>::iterator vIntItr;
    vectorInt _vector;

    PmergeMe();
    void MergeSort();
    void InsertionSort();
    void moveNum( vIntItr &left, vIntItr &right );

public:
    PmergeMe( vectorInt input );
    ~PmergeMe();

    void printVector();
};

#endif