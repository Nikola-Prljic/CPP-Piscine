#include "PmergeMe.hpp"

PmergeMe::PmergeMe( vectorInt input ) : _vector(input), _list(), _listofList(), _groups_ammount(ceilf((double)_vector.size() / (double)5)), _N(5)
{
    int N = 5;
    if( _vector.size() > 5000 )
    {
        std::cout << "Error" << std::endl << "Vector size bigger than 5000" << std::endl;
        return ;
    }
    /* _groups_ammount = ceilf((double)_vector.size() / (double)N); */
    convertVectorToList();
    SortList();
    printListofList();

    sortVector(N);
    //printList();
    /* std::cout << "sorted:" << std::endl;
    printVector(); */
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

void PmergeMe::printList()
{
    for( listIntItr itr = _list.begin(); itr != _list.end(); itr++ )
        std::cout << *itr << std::endl;
}

void PmergeMe::printListofList()
{
    for( listofListItr y = _listofList.begin(); y != _listofList.end(); y++ )
    {
        for( listIntItr x = y->begin(); x != y->end(); x++)
            std::cout << *x << " ";
        std::cout << std::endl;
    }
}

std::vector<int> PmergeMe::getVector() { return _vector; }

//---------------------------------queue-----------------------------------------------//

void PmergeMe::convertVectorToList()
{
    int x = 1;
    listInt x_line;
    listofListItr y_itr = _listofList.begin();
    for( vIntItr vItr = _vector.begin(); vItr != _vector.end(); vItr++ )
    {
        x_line.push_back(*vItr);
        if(x == _N || vItr + 1 == _vector.end())
        {
            _listofList.push_back(x_line);
            y_itr++;
            x_line.clear();
            x = 1;
        }
        else
            x++;
    }
}

void PmergeMe::SortList()
{
    InsertionSortSplitList( 5 );
}

std::list<int>::iterator PmergeMe::increaseList( std::list<int>::iterator itr, int n )
{
    for( int i = 0; i < n && itr != _list.end(); i++ )
        itr++;
    if( itr == _list.end() )
        itr--;
    return itr;
}

void PmergeMe::InsertionSortSplitList( int N )
{
    (void)N;
    for( listofListItr y = _listofList.begin(); y != _listofList.end(); y++ )
        InsertionSort(*y);
}

void PmergeMe::InsertionSort( listInt &list )
{
    for( listIntItr left = list.begin(); left != list.end(); left++ )
        for( listIntItr right = left; right != list.end(); right++ )
            if( *left > *right)
                moveNum( left, right);
}

void PmergeMe::moveNum( listIntItr &left, listIntItr &right )
{
    listIntItr tmp = left;
    int rightInttmp = *right;

    _list.erase ( right );
    _list.insert ( left, rightInttmp );
    left = tmp;
}