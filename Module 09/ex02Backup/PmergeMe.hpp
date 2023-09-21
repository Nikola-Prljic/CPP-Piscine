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
    int _groups_ammount;

    PmergeMe();

    void sortVector( int N );
    void InsertionSortSplit( int N );
    bool InsertionSort_size_smaller_N( int N );
    void InsertionSort(vIntItr start, vIntItr end );
    void moveNum( vIntItr &left, vIntItr &right );
    void MergeSortGroups( int N);
    void MergeSort( vIntItr right, vIntItr right_end );

public:
    PmergeMe( vectorInt input );
    ~PmergeMe();

    void printVector();
};


#endif