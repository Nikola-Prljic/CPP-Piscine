#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <iostream>
# include <algorithm>
# include <functional>
# include <tgmath.h>
# include <list>

class PmergeMe
{

private:
    typedef std::vector< int > vectorInt;
    typedef std::vector< int >::iterator vIntItr;
    typedef std::list< int > listInt;
    typedef std::list< int >::iterator listIntItr;

    vectorInt _vector;
    listInt _list;

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
    void SortList();
    void InsertionSortSplitList( int N );

public:
    PmergeMe( vectorInt input );
    ~PmergeMe();

    void printVector();
    std::vector<int> getVector();
};

std::list<int>::iterator &operator+( std::list<int>::iterator &itr, int n );

#endif