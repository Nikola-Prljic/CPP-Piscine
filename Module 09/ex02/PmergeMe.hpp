#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <tgmath.h>
#include <queue>

class PmergeMe
{

private:
    typedef std::vector<int> vectorInt;
    typedef std::vector<int>::iterator vIntItr;
    typedef std::queue<int> queueInt;

    vectorInt _vector;
    queueInt _queue;

    int _groups_ammount;

    PmergeMe();

    void sortVector( int N );
    void InsertionSortSplit( int N );
    bool InsertionSort_size_smaller_N( int N );
    void InsertionSort(vIntItr start, vIntItr end );
    void moveNum( vIntItr &left, vIntItr &right );
    void MergeSortGroups( int N);
    void MergeSort( vIntItr right, vIntItr right_end );
    
    void convertVectorToQuene();
public:
    PmergeMe( vectorInt input );
    ~PmergeMe();

    void printVector();
    std::vector<int> getVector();
};


#endif