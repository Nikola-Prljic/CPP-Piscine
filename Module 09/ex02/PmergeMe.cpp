#include "PmergeMe.hpp"

PmergeMe::PmergeMe( vectorInt input ) : _vector(input), _queue(), _groups_ammount(0)
{
    if( _vector.size() > 5000 )
    {
        std::cout << "Error" << std::endl << "Vector size bigger than 5000" << std::endl;
        return ;
    }
    sortVector(5);
    std::cout << "sorted:" << std::endl;
    printVector();
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector( int N )
{
    if(InsertionSort_size_smaller_N(N) == true)
        return ;
    InsertionSortSplit( N );
    MergeSortGroups( N );
}

//------------------------Vector------------------------//
//--------------------InsertionSort--------------------//
void PmergeMe::InsertionSortSplit( int N )
{
    vIntItr start; 
    vIntItr end;

    start = _vector.begin();
    end = _vector.begin() + N;
    _groups_ammount = ceilf((double)_vector.size() / (double)N);
    for(int i = 0; i < _groups_ammount; i++)
    {
        InsertionSort( start, end);
        start += N;
        end += N;
    }
}

void PmergeMe::InsertionSort( vIntItr start, vIntItr end)
{
    for( vIntItr left = start; left != _vector.end() && left != end; left++ )
        for( vIntItr right = left; right != _vector.end() && right != end; right++ )
            if( *left > *right)
                moveNum( left, right );
}

bool PmergeMe::InsertionSort_size_smaller_N( int N )
{
    if( (int)_vector.size() > N )
        return false;
    for( vIntItr left = _vector.begin(); left != _vector.end(); left++ )
        for( vIntItr right = left; right != _vector.end(); right++ )
            if( *left > *right)
                moveNum( left, right );
    return true;
}

void PmergeMe::moveNum( vIntItr &left, vIntItr &right )
{
    vIntItr tmp = left;
    int rightInttmp = *right;
    _vector.erase ( right );
    _vector.insert ( left, rightInttmp );
    left = tmp;
}

//----------------------MergeSort----------------------//
void PmergeMe::MergeSortGroups( int N )
{
    vIntItr right;
    vIntItr right_end;
    int mergeSortItrarations;

    right = _vector.begin() + N;
    right_end = _vector.begin() + N * 2;
    mergeSortItrarations = _groups_ammount - 1;
    for(int i = 0; i < mergeSortItrarations; i++)
    {
        MergeSort( right, right_end );
        right = right_end;
        right_end += N;
    }
}

void PmergeMe::MergeSort( vIntItr right, vIntItr right_end )
{
    vIntItr left = _vector.begin();

    for(; left != right && right != _vector.end() && right != right_end; left++)
        if(*left > *right)
        {
            moveNum( left, right );
            right++;
        }
}

void PmergeMe::printVector()
{
    for( std::vector<int>::iterator itr = _vector.begin(); itr != _vector.end(); itr++ )
        std::cout << *itr << std::endl;
}

std::vector<int> PmergeMe::getVector() { return _vector; }

//---------------------------------queue-----------------------------------------------//
void PmergeMe::convertVectorToQuene()
{
    for( vIntItr vItr = _vector.begin(); vItr != _vector.end(); vItr++ )
        _list.push_back(*vItr);
}

void PmergeMe::SortList()
{
    InsertionSortSplitList( 10 );
}

std::list<int>::iterator &operator+( std::list<int>::iterator &itr, int n )
{
    for( int i = 0; i < n; n++ )
        itr++;
    return itr;
}

void PmergeMe::InsertionSortSplitList( int N )
{
    listIntItr start; 
    listIntItr end;

    start = _list.begin();
    end = _list.begin() + 5;
    _groups_ammount = ceilf((double)_list.size() / (double)N);
    for(int i = 0; i < _groups_ammount; i++)
    {
        InsertionSort( start, end);
        start += N;
        end += N;
    }
}