#include <bits/stdc++.h>
#include "PmergeMe.hpp"
#include <stdlib.h>

int argvToVector( char **argv, std::vector<int> &input )
{
    int num = 0;
    for( int i = 1; argv[i]; i++ )
    {
        if( argv[i][0] == '0' && argv[i][1] == 0 ){
            input.push_back(0);
            continue ;
        }
        if( argv[i][0] == '-' && argv[i][1] == '1' && argv[i][2] == 0 ){
            input.push_back(-1);
            continue ;
        }
        num = std::atoi(argv[i]);
        if( num == 0 || num == -1)
        {
            std::cout << "Error: wrong input" << std::endl;
            return 1;
        }
        else
            input.push_back(num);
    }
    return 0;
}

void tester( std::vector<int> MergeInsertSort, std::vector<int> input )
{
    if(MergeInsertSort.empty())
        return ;
    std::sort( input.begin(), input.end() );
    if( !equal( input.begin(), input.end(), MergeInsertSort.begin() ) )
        std::cout << "Error\nVector is wrong sorted" << std::endl;
}

void tester( std::list<int> list, std::vector<int> input )
{
    if(list.empty())
        return ;
    std::sort( input.begin(), input.end() );
    if( !equal( input.begin(), input.end(), list.begin() ) )
        std::cout << "Error\nList is wrong sorted" << std::endl;
}

void sort_and_get_time( PmergeMe &sort )
{
    clock_t t;

    t = clock();
    sort.sortVector();
    t = clock() - t;
    double time_vector = ((double)t) / CLOCKS_PER_SEC;
    t = clock();
    sort.SortList();
    t = clock() - t;
    double time_list = ((double)t) / CLOCKS_PER_SEC;
    std::cout << "After: ";
    sort.printVector();
    std::cout << "Before: ";
    sort.printVector();
    std::cout << std::fixed << "Time to process a range of " << sort.getVector().size() << " elements with std::vector<int> " << time_vector << " us" << std::endl;
    std::cout << "List took " << time_list << " seconds to sort" << std::endl;
}

int main ( int argc, char **argv )
{
    (void)argv;
    if(argc == 1)
        return (1);
    std::vector<int> input;
    if(argvToVector( argv, input ))
        return (1);
    PmergeMe sort( input );
    /* sort_and_get_time( sort ); */
    std::cout << sort;
    tester( sort.getVector(), input );
    tester( sort.getList(), input );
    /* sort.printVector();
    sort.printListofList(); */
    return (0);
}
