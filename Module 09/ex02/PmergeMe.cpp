#include "PmergeMe.hpp"

PmergeMe::PmergeMe( vectorInt input ) : _vector(input), _listofList(), _groups_ammount(ceilf((double)_vector.size() / (double)5)), _N(5)
{
    if( _vector.size() > 5000 )
    {
        std::cout << "Error" << std::endl << "Vector size bigger than 5000" << std::endl;
        _vector.clear();
        return ;
    }
    convertVectorToList();
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector()
{
    if(_vector.empty())
    {
        std::cout << "Vector is empty." << std::endl;
        return ;
    }
    if(InsertionSort_size_smaller_N(_N) == true)
        return ;
    InsertionSortSplit( _N );
    MergeSortGroups( _N );
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
    int rightInttmp = *right;
    _vector.erase ( right );
    left = _vector.insert ( left, rightInttmp );
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
        std::cout << *itr << " ";
    std::cout << "Vector" << std::endl;
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

void PmergeMe::printList( std::list<int> list )
{
    for( listIntItr x = list.begin(); x != list.end(); x++)
        std::cout << *x << " ";
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
    if(_listofList.empty())
    {
        std::cout << "List of list is empty." << std::endl;
        return ;
    }
    for( listofListItr y = _listofList.begin(); y != _listofList.end(); y++ )
        InsertionSort(*y);
    MergeSortGroups();
}

std::list<int>::iterator PmergeMe::increaseList( std::list<int>::iterator itr, int n, listInt &list )
{
    for( int i = 1; i < n && itr != list.end(); i++ )
        itr++;
    return itr;
}

void PmergeMe::InsertionSort( listInt &list )
{
    int pos_right;
    int pos_left = 0;
    for( listIntItr left = list.begin(); left != list.end(); left++ )
    {
        pos_right = pos_left;
        for( listIntItr right = left; right != list.end(); right++)
        {
            if( *left > *right)
            {
                moveNum( left, right, list);
                right =  increaseList(list.begin(), pos_right, list);
                left = increaseList(list.begin(), pos_left, list);
            }
            pos_right++;
        }
        pos_left++;
    }
}

void PmergeMe::moveNum( listIntItr &left, listIntItr &right, listInt &list )
{
    int rightInttmp = *right;

    list.erase ( right );
    list.insert ( left, rightInttmp );
}


void PmergeMe::MergeSortGroups()
{
    listofListItr lolItr = _listofList.begin();
    lolItr++;
    while( lolItr != _listofList.end() )
    {
        MergeSort( _listofList.front(), *lolItr );
        _listofList.erase(lolItr);
        lolItr = _listofList.begin();
        lolItr++;
    }
}

void PmergeMe::MergeSort( listInt &firstList, listInt &megeList )
{
    int pos_left = 0;
    listIntItr left = firstList.begin();
    listIntItr right = megeList.begin();

    for(; left != firstList.end() && right != megeList.end(); left++)
    {
        if(*left > *right)
        {
            InsertLeft_popRight( left, right, firstList, megeList);
            left = increaseList(firstList.begin(), pos_left, firstList);
        }
        pos_left++;
    }
    if(megeList.empty() == true)
        return ;
    for(right = megeList.begin(); right != megeList.end(); right++)
        firstList.push_back(*right);
    megeList.clear();
}

void PmergeMe::InsertLeft_popRight( listIntItr &left, listIntItr &right, listInt &firstList, listInt &megeList )
{
    firstList.insert( left, *right );
    megeList.pop_front();
    right = megeList.begin();
}

std::list<int> PmergeMe::getList() { return _listofList.front(); }
