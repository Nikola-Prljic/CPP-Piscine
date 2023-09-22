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
    typedef std::list< std::list< int > > listofList;
    typedef std::list< std::list< int > >::iterator listofListItr;

    vectorInt _vector;
    listInt _list;
    listofList _listofList;

    int _groups_ammount;
    int _N;

    PmergeMe();

    void sortVector( int N );
    void InsertionSortSplit( int N );
    bool InsertionSort_size_smaller_N( int N );
    void InsertionSort(vIntItr start, vIntItr end );
    void moveNum( vIntItr &left, vIntItr &right );
    void MergeSortGroups( int N);
    void MergeSort( vIntItr right, vIntItr right_end );
    
    std::list<int>::iterator increaseList( std::list<int>::iterator itr, int n );
    void printList();
    void printListofList();
    void convertVectorToList();
    void SortList();
    void InsertionSortSplitList( int N );
    void InsertionSort( listInt &_list );
    void moveNum( listIntItr &left, listIntItr &right );

public:
    PmergeMe( vectorInt input );
    ~PmergeMe();

    void printVector();
    std::vector<int> getVector();
};

#endif