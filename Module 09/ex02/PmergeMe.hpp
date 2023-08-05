#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

class PmergeMe
{

private:
    typedef std::vector<int> vectorInt;
    typedef std::vector<int>::iterator vIntItr;
    vectorInt _vector;
    vectorInt _vSorted;

    PmergeMe();
    void sortPairs();
    void InsertionSort( std::vector<int> &vecNum );
    void moveNum( vIntItr &left, vIntItr &right, std::vector<int> &vecNum );
    void mergeVectors();

    void InsertionSortAdcanced( std::vector<int> &vecNum );

public:
    PmergeMe( vectorInt input );
    ~PmergeMe();

    void printVunSorted();
    void printVSorted();
};

#endif