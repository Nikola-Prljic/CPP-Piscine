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

int get_time_of_input( char **argv, std::vector<int> &input, int &time )
{
    clock_t t;

    t = clock();
    if(argvToVector( argv, input ))
        return (1);
    t = clock() - t;
    time = ((double)t) / CLOCKS_PER_SEC;
    return (0);
}

void tester( std::vector<int> MergeInsertSort, std::vector<int> input )
{
    if(MergeInsertSort.empty())
    {
        std::cout << "Error\nVector is Empty" << std::endl;
        return ;
    }
    std::sort( input.begin(), input.end() );
    if( !equal( input.begin(), input.end(), MergeInsertSort.begin() ) )
        std::cout << "Error\nVector is wrong sorted" << std::endl;
}

void tester( std::list<int> list, std::vector<int> input )
{
    if(list.empty())
    {
        std::cout << "Error\nList is Empty" << std::endl;
        return ;
    }
    std::sort( input.begin(), input.end() );
    if( !equal( input.begin(), input.end(), list.begin() ) )
        std::cout << "Error\nList is wrong sorted" << std::endl;
}

int main ( int argc, char **argv )
{
    int argv_to_vector_time;
    if(argc == 1)
        return (1);
    std::vector<int> input;
    if(get_time_of_input( argv, input, argv_to_vector_time ))
        return (1);
    PmergeMe sort( input, argv_to_vector_time);
    std::cout << sort;
    tester( sort.getVector(), input );
    tester( sort.getList(), input );
    return (0);
}
