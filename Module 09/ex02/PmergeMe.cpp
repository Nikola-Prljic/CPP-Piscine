#include "PmergeMe.hpp"

PmergeMe::PmergeMe( vectorInt input ) : _vector(input) 
{
    //InsertionSort();
    MergeSort();
}

PmergeMe::~PmergeMe() {}

void ft_swap(int &n1, int &n2)
{
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

//----------------------MergeSort----------------------//
void PmergeMe::MergeSort()
{
    vIntItr left = _vector.begin();
    for( vIntItr rigth = _vector.begin() + 1; left != _vector.end(); rigth += 2 )
    {
        if(left[0] > rigth[0])
            ft_swap( left[0], rigth[0]);
        left += 2;
    }
}

//--------------------InsertionSort--------------------//
void PmergeMe::InsertionSort()
{
    for( vIntItr left = _vector.begin(); left != _vector.end(); left++ )
        for( vIntItr right = left; right != _vector.end(); right++ )
            if( left[0] > right[0])
                moveNum( left, right );
}

void PmergeMe::moveNum( vIntItr &left, vIntItr &right )
{
    vIntItr tmp = left;
    int rightInttmp = right[0];
    _vector.erase ( right );
    _vector.insert ( left, rightInttmp );
    left = tmp;
}

void PmergeMe::printVector()
{
    for( vIntItr itr = _vector.begin(); itr != _vector.end(); itr++ )
        std::cout << itr[0] << std::endl;
}
