#include "PmergeMe.hpp"

PmergeMe::PmergeMe( vectorInt input ) : _vector(input), _vSorted()
{
    sortPairs();
    printVunSorted();
    std::cout << std::endl;
    InsertionSortAdcanced( _vector );
    InsertionSort( _vector ); // still wrong !!!
    /* printVunSorted(); */
    /* InsertionSort( _vSorted ); */
    /* std::cout << std::endl << "Sorted :" << std::endl; */
    /* mergeVectors(); */
    printVunSorted();
}

PmergeMe::~PmergeMe() {}

void ft_swap(int &n1, int &n2)
{
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void PmergeMe::mergeVectors()
{
    /* for( vIntItr itr = _vector.begin(); itr != _vector.end(); itr++ )
    {
        for( vIntItr itrSorted = _vSorted.begin(); itrSorted  != _vSorted.end(); itrSorted++ )
        {
            if( itr[0] <= itrSorted[0] )
            {
                _vSorted.insert(itrSorted, itr[0]);
                break ;
            }
            else if( itrSorted == --_vSorted.end() )
            {
                _vSorted.push_back(itr[0]);
                break ;
            }
        }
    } */
}

//----------------------MergeSort----------------------//
void PmergeMe::sortPairs()
{
    int i = 0;
    vIntItr itrEnd = _vector.end();
    if(_vector.size() % 2 != 0)
        itrEnd--;
    for( vIntItr itr = _vector.begin(); itr != itrEnd; itr++ )
        if( i++ % 2 == 0 && *itr > *(itr + 1) )
            ft_swap( *itr, *(itr + 1) );
}

void PmergeMe::InsertionSortAdcanced( std::vector<int> &vecNum )
{
    for( vIntItr left = vecNum.begin(); left != vecNum.end(); left += 2 )
        for( vIntItr right = left; right != vecNum.end(); right += 2 )
            if( left[0] > right[0] )
            {
                ft_swap( *left, *right );
                ft_swap( *(left + 1), *(right + 1) );
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

void printVector( std::vector<int> vector )
{
    /* std::vector<int>::iterator itrLastOne = --vector.end(); */
    for( std::vector<int>::iterator itr = vector.begin(); itr != vector.end(); itr++ )
    {
        std::cout << itr[0] << std::endl;
        /* if( itr != itrLastOne ) */
            /* std::cout << " "; */
    }
    /* std::cout << std::endl; */
}

void PmergeMe::printVunSorted()
{
    printVector( _vector );
}

void PmergeMe::printVSorted()
{
    printVector( _vSorted );
}
