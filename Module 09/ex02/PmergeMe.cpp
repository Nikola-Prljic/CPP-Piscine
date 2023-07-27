#include "PmergeMe.hpp"

PmergeMe::PmergeMe( vectorInt input ) : _vector(input) 
{
    InsertionSort();
}

PmergeMe::~PmergeMe() {}

void PmergeMe::moveNum( vIntItr &left, vIntItr &right )
{
    vIntItr tmp = left;
    int rightInttmp = right[0];
    _vector.erase ( right );
    _vector.insert ( left, rightInttmp );
    left = tmp;
}

void PmergeMe::InsertionSort()
{
    for( vIntItr left = _vector.begin(); left != _vector.end(); left++ )
        for( vIntItr right = left; right != _vector.end(); right++ )
            if( left[0] > right[0])
                moveNum( left, right );
}

void PmergeMe::printVector()
{
    for( vIntItr itr = _vector.begin(); itr != _vector.end(); itr++ )
        std::cout << itr[0] << std::endl;
}
