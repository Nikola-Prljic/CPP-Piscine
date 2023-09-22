#include "PmergeMe.hpp"

PmergeMe::PmergeMe( vectorInt input ) : _vector(input), _list(), _listofList(), _groups_ammount(ceilf((double)_vector.size() / (double)5))
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
    sortVector(N);
    printList();
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

std::vector<int> PmergeMe::getVector() { return _vector; }

//---------------------------------queue-----------------------------------------------//

void PmergeMe::convertVectorToList()
{
    int x = 0;
    /* int y = 0; */
    listofListItr y_itr = _listofList.begin();
    listInt x_line;
    listIntItr x_line_itr = x_line.begin();
    listIntItr itr_x;
    for( vIntItr vItr = _vector.begin(); vItr != _vector.end(); vItr++ )
    {
        x_line.push_back(*vItr);
        if(x == _N)
        {
            _listofList.push_back(x_line);
            y_itr++;
            x_line.clear();
            /* listIntItr  */x_line_itr = x_line.begin();
        }
        else
        {
            x_line_itr++;
            x++;
        }
    }
    exit(1);
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
    int start_index = 0;
    int end_index = N;
    listIntItr start; 
    listIntItr end;

    start = _list.begin();
    end = increaseList( _list.begin(), N );
    for(int i = 0; i < _groups_ammount; i++)
    {
        std::cout << "start = " << *start << std::endl;
        std::cout << "end = " << *end << std::endl;
        InsertionSort( start, end);
        start_index += N;
        end_index += N;
        start = increaseList( _list.begin(), start_index );
        end = increaseList( _list.begin(), end_index );
    }
}

void PmergeMe::InsertionSort( listIntItr start, listIntItr end)
{
    int pos_left = 0;
    for( listIntItr left = start; left != _list.end() && left != end; left++ )
    {
        for( listIntItr right = left; right != _list.end() && right != end; right++ )
        {
            if( *left > *right)
            {
                moveNum( left, right, pos_left );
            }
            /* std::cout << "+" << *right << std::endl; */
        }
        pos_left++;
    }
}

void PmergeMe::moveNum( listIntItr &left, listIntItr &right, int pos_left )
{
    /* listIntItr tmp = left; */
    int rightInttmp = *right;
    _list.erase ( right );
    _list.insert ( left, rightInttmp );
    left = increaseList( _list.begin(), pos_left );
}