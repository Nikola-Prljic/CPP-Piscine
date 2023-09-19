#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <tgmath.h>

class PmergeMe
{

private:
    typedef std::vector<int> vectorInt;
    typedef std::vector<int>::iterator vIntItr;
    vectorInt _vector;
    vectorInt _vSorted;
    int _groups_ammount;


    PmergeMe();
    void sortVector( int N );
    void InsertionSort( std::vector<int> &vecNum , vIntItr start, vIntItr end );
    void InsertionSort( std::vector<int> &vecNum );
    void InsertionSortSplit( std::vector<int> &vecNum, int N );
    void moveNum( vIntItr &left, vIntItr &right, std::vector<int> &vecNum );
    void MergeSort( std::vector<int> &vecNum, int N );

public:
    PmergeMe( vectorInt input );
    ~PmergeMe();

    void printVunSorted();
    void printVSorted();
};

void printVector( std::vector<int> vector );

#endif