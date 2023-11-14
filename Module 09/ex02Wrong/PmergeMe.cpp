#include "PmergeMe.hpp"

PmergeMe::PmergeMe( const vectorInt input, int argv_to_vector_time ) : _vector(input), _unsortedVector(input),_listofList(), _groups_ammount(ceilf((double)_vector.size() / (double)5)), _N(5), _time_vector(argv_to_vector_time), _time_listofList(argv_to_vector_time)
{
    if( input.empty() == true )
        return ;
    if( _vector.size() > 5000 )
    {
        std::cout << "Error" << std::endl << "Vector size bigger than 5000" << std::endl;
        _vector.clear();
        return ;
    }
    sort_and_get_time( _time_vector, &PmergeMe::sortVector );
    sort_and_get_time( _time_listofList, &PmergeMe::SortList );
}

PmergeMe::PmergeMe( PmergeMe const &in )
{
    _vector = in._vector;
    _unsortedVector = in._unsortedVector;
    _listofList = in._listofList;
    _groups_ammount = in._groups_ammount;
    _N = in._N;
    _time_vector = in._time_vector;
    _time_listofList = in._time_listofList;
}

PmergeMe const &PmergeMe::operator=( PmergeMe const &in )
{
    if (this == &in)
        return *this;
    if(in._vector.empty())
        _vector.clear();
    else
        _vector = in._vector;
    if(in._unsortedVector.empty())
        _unsortedVector.clear();
    else
        _unsortedVector = in._unsortedVector;
    if(in._listofList.empty())
    {
        while (_listofList.empty())
            _listofList.front().clear();
    }
    else
        _listofList = in._listofList;
    _groups_ammount = in._groups_ammount;
    _N = in._N;
    _time_vector = in._time_vector;
    _time_listofList = in._time_listofList;
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort_and_get_time( double &time, void (PmergeMe::*func)() )
{
    clock_t t;

    t = clock();
    (this->*func)();
    t = clock() - t;
    time += ((double)t) / CLOCKS_PER_SEC;
}

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

//------------------------Vector------------------------//
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

//---------------------------------list-----------------------------------------------//

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
    convertVectorToList();
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
    for( listIntItr left = list.begin(); left != list.end(); left++ )
        for( listIntItr right = left; right != list.end(); )
            if( *left > *right)
                moveNum( left, right, list);
            else
                right++;
}

void PmergeMe::moveNum( listIntItr &left, listIntItr &right, listInt &list )
{
    left = list.insert ( left, *right );
    right = list.erase ( right );
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

std::vector<int> PmergeMe::getUnsortedVector() { return _unsortedVector; }

double PmergeMe::get_time_vector() { return _time_vector; }
    
double PmergeMe::get_time_ListofList() { return _time_listofList; }

void PmergeMe::printVector()
{
    for (std::vector<int>::iterator itr = _vector.begin(); itr != _vector.end(); itr++ )
        std::cout << *itr << " ";
    std::cout << std::endl;
}

void VectorTo_ostream( std::ostream &os, std::vector<int> vector )
{
    for( std::vector<int>::iterator itr = vector.begin(); itr != vector.end(); itr++ )
        os << *itr << " ";
    os << std::endl;
}

std::ostream& operator<<( std::ostream& os, PmergeMe& dt )
{
    os << "Before: ";
    VectorTo_ostream( os, dt.getUnsortedVector() );
    os << "After: ";
    VectorTo_ostream( os, dt.getVector() );
    os << std::fixed << "Time to process a range of " << dt.getVector().size() << " elements with std::vector<int> " << dt.get_time_vector() << " s" << std::endl;
    os << std::fixed << "Time to process a range of " << dt.getVector().size() << " elements with std::vector<int> " << dt.get_time_ListofList() << " s" << std::endl;
    return os;
}
