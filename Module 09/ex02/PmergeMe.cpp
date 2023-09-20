#include "PmergeMe.hpp"

PmergeMe::PmergeMe( vectorInt input ) : _vector(input), _vSorted(), _groups_ammount(0)
{
    std::cout << std::endl;
    sortVector(5);
    std::cout << "sorted:" << std::endl;
    printVector(_vector);
    /* MergeSort( _vector );
    printVector(_vector); */
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector( int N )
{
    std::cout << "len = " << _vector.size() << std::endl;
    if((int)_vector.size() <= N)
    {
        InsertionSort(_vector);
        return ;
    }
    InsertionSortSplit( _vector, N);
    MergeSortGroups( _vector, N );
}

void ft_swap(int &n1, int &n2)
{
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}
//----------------------MergeSort----------------------//

void PmergeMe::MergeSortGroups( std::vector<int> &vecNum, int N )
{
    int steps = N;
    int end_pos = N * 2;
    vIntItr right;
    vIntItr right_end;
    int mergeSortItraration;

    mergeSortItraration = _groups_ammount - 1;
    for(int i = 0; i < mergeSortItraration; i++)
    {
        right = vecNum.begin() + N;
        right_end = vecNum.begin() + end_pos;
        MergeSort( vecNum, right, right_end );
        N += steps;
        end_pos += steps;
    }
}

void PmergeMe::MergeSort( std::vector<int> &vecNum, vIntItr right, vIntItr right_end )
{
    vIntItr left = vecNum.begin();
    /* vIntItr left_end = vecNum.begin() + N * 2; */
    /* vIntItr right = vecNum.begin() + N;
    vIntItr right_end = vecNum.begin() + 2 * N; */

    for(; right != vecNum.end() && right != right_end; left++)
        if(*left > *right)
        {
            moveNum( left, right, vecNum );
            right++;
        }
}

void printVector( std::vector<int> vector )
{
    for( std::vector<int>::iterator itr = vector.begin(); itr != vector.end(); itr++ )
        std::cout << *itr << std::endl;
}
//--------------------InsertionSort--------------------//
void PmergeMe::InsertionSortSplit( std::vector<int> &vecNum, int N )
{
    vIntItr start; 
    vIntItr end;

    start = vecNum.begin();
    end = vecNum.begin() + N;
    _groups_ammount = ceilf((double)vecNum.size() / (double)N);
    for(int i = 0; i < _groups_ammount ; i++)
    {
        InsertionSort(vecNum, start, end);
        start += N;
        end += N;
    }
}

void PmergeMe::InsertionSort( std::vector<int> &vecNum, vIntItr start, vIntItr end)
{
    for( vIntItr left = start; left != vecNum.end() && left != end; left++ )
        for( vIntItr right = left; right != vecNum.end() && right != end; right++ )
            if( *left > *right)
                moveNum( left, right, vecNum );
}

void PmergeMe::InsertionSort( std::vector<int> &vecNum )
{
    for( vIntItr left = vecNum.begin(); left != vecNum.end(); left++ )
        for( vIntItr right = left; right != vecNum.end(); right++ )
            if( *left > *right)
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


void PmergeMe::printVunSorted() { printVector( _vector ); }

void PmergeMe::printVSorted() { printVector( _vSorted ); }
