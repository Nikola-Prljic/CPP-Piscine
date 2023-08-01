#include "PmergeMe.hpp"

PmergeMe::PmergeMe( vectorInt input ) : _vector(input), _vSorted()
{
    sortPairs();
    printVector();
    InsertionSort( _vSorted );
    std::cout << "Sorted :" << std::endl;
    printVSorted();
}

PmergeMe::~PmergeMe() {}

void ft_swap(int &n1, int &n2)
{
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

/* void PmergeMe::mergeVectors()
{
    for( vIntItr itr = _vector.begin(); itr != _vector.end(); itr++ )
    {
        for( vIntItr itrVec = _vector.begin(); itrVec != _vector.end(); itrVec++ )
        {
            if
        }
    }
} */

//----------------------MergeSort----------------------//
void PmergeMe::sortPairs()
{
    size_t reduce = 0;
    vIntItr itr, itr2;
    size_t len = _vector.size();
    if( len % 2 != 0 )
        len--;
    for( size_t i = 0; i < len; i++ )
    {
        if( i % 2 == 0)
        {
            itr = _vector.begin() + (i - reduce);
            itr2 = itr + 1;
            if( itr[0] > itr2[0])
                ft_swap( itr[0], itr2[0] );
            _vSorted.push_back( itr[0] );
            _vector.erase(itr);
            reduce++;
        }
    }
}

//--------------------InsertionSort--------------------//
void PmergeMe::InsertionSort( std::vector<int> &vecNum )
{
    for( vIntItr left = vecNum.begin(); left != vecNum.end(); left++ )
        for( vIntItr right = left; right != vecNum.end(); right++ )
            if( left[0] > right[0])
                moveNum( left, right, vecNum );
}

void PmergeMe::moveNum( vIntItr &left, vIntItr &right, std::vector<int> &vecNum )
{
    vIntItr tmp = left;
    int rightInttmp = right[0];
    vecNum.erase ( right );
    vecNum.insert ( left, rightInttmp );
    left = tmp;
}

void PmergeMe::printVector()
{
    for( vIntItr itr = _vector.begin(); itr != _vector.end(); itr++ )
        std::cout << itr[0] << std::endl;
}

void PmergeMe::printVSorted()
{
    for( vIntItr itr = _vSorted.begin(); itr != _vSorted.end(); itr++ )
        std::cout << itr[0] << std::endl;
}
