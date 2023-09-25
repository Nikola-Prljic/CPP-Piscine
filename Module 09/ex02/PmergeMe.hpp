#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <iostream>
# include <algorithm>
//# include <functional>
# include <tgmath.h>
# include <list>
# include <ctime>

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
    vectorInt _unsortedVector;
    listofList _listofList;

    int _groups_ammount;
    int _N;
    double _time_vector;
    double _time_listofList;

    PmergeMe();

    void sortVector();
    void sort_and_get_time( double &time, void (PmergeMe::*func)() );
    void InsertionSortSplit( int N );
    bool InsertionSort_size_smaller_N( int N );
    void InsertionSort(vIntItr start, vIntItr end );
    void moveNum( vIntItr &left, vIntItr &right );
    void MergeSortGroups( int N);
    void MergeSort( vIntItr right, vIntItr right_end );
    
    void SortList();
    void convertVectorToList();
    void InsertionSort( listInt &_list );
    void moveNum( listIntItr &left, listIntItr &right, listInt &list );
    void MergeSortGroups();
    void MergeSort( listInt &firstList, listInt &megeList );
    void InsertLeft_popRight( listIntItr &left, listIntItr &right, listInt &firstList, listInt &megeList );
    std::list<int>::iterator increaseList( std::list<int>::iterator itr, int n, listInt &list );
    void printList( std::list<int> list );

public:

    PmergeMe( const vectorInt input );
    PmergeMe( PmergeMe const &in );
    ~PmergeMe();

    PmergeMe const &operator=( PmergeMe const &in );
    void printListofList();
    void printVector();

    std::vector<int> getVector();
    std::vector<int> getUnsortedVector();
    std::list<int> getList();
    double get_time_vector();
    double get_time_ListofList();

};

std::ostream& operator<<(std::ostream& os, PmergeMe& dt);

#endif