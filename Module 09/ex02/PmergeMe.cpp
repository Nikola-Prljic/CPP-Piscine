#include "PmergeMe.hpp"

PmergeMe::PmergeMe( vectorInt input ) : _vector(input), _vSorted()
{
    std::cout << std::endl;
    sortVector(10);
    std::cout << "sorted:" << std::endl;
    printVector(_vSorted);
    /* MergeSort( _vector );
    printVector(_vector); */
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector( int N )
{
    std::cout << "len = " << _vector.size() << std::endl;
    if((int)_vector.size() <= N)
        InsertionSort(_vector);
    else
    {
        InsertionSortSplit( _vector, N);
        MergeSort( _vector, N );
    }
}

void ft_swap(int &n1, int &n2)
{
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}
//----------------------MergeSort----------------------//

void PmergeMe::MergeSort( std::vector<int> &vecNum, int N )
{
    vIntItr left = vecNum.begin();
    vIntItr right = vecNum.begin() + N;
    for(int i = 0; i < N; i++)
    {
        if(*left < *right)
        {
            _vSorted.push_back(*left);
            _vSorted.push_back(*right);
        }
        else
        {
            _vSorted.push_back(*right);
            _vSorted.push_back(*left);
        }
        /* else
            vecNum.insert(vecNum.begin() + std::distance(vecNum.begin() + 1, left), *right); */
        right++;
        left++;
    }
}

void printVector( std::vector<int> vector )
{
    for( std::vector<int>::iterator itr = vector.begin(); itr != vector.end(); itr++ )
        std::cout << itr[0] << std::endl;
}
//--------------------InsertionSort--------------------//
void PmergeMe::InsertionSortSplit( std::vector<int> &vecNum, int N )
{
    N--;
    int count = 0, i = 0;
    int groups_ammount = ceil((double)vecNum.size() / (double)N);
    
    std::vector<int> groups[groups_ammount];
    for(vIntItr left = vecNum.begin(); left != vecNum.end(); left++)
    {
        groups[i].push_back(left[0]);
        if(count == N && i < N)
        {
            count = 0;
            i++;
        }
        count++;
    }
    for(i = 0; i < groups_ammount; i++)
        InsertionSort(groups[i]);
    i = 0;
    vIntItr ItrGroups = groups[i].begin();
    for(vIntItr left = vecNum.begin(); left != vecNum.end(); left++)
    {

        left[0] = ItrGroups[0];
        ItrGroups++;
        if(ItrGroups == groups[i].end())
        {
            i++;
            ItrGroups = groups[i].begin();
        }
    }
    printVector(vecNum);
}

void PmergeMe::InsertionSort( std::vector<int> &vecNum)
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


void PmergeMe::printVunSorted() { printVector( _vector ); }

void PmergeMe::printVSorted() { printVector( _vSorted ); }
