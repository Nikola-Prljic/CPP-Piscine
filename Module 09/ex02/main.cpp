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
        num = std::atoi(argv[i]);
        if(num)
            input.push_back(num);
        else
        {
            std::cout << "Error: wrong input" << std::endl;
            return 1;
        }
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

int main ( int argc, char **argv )
{
    if(argc == 1)
        return 1;

    clock_t t;

    std::vector<int> input;
    if(argvToVector( argv, input ))
        return 1;


    PmergeMe sort( input );

    t = clock();
    sort.sortVector();
    t = clock() - t;
    double time_vector = ((double)t) / CLOCKS_PER_SEC;

    tester( sort.getVector(), input );

    t = clock();
    sort.SortList();
    t = clock() - t;
    double time_list = ((double)t) / CLOCKS_PER_SEC;
 
    printf("Vector took %f seconds to execute \n", time_vector);
    printf("List took %f seconds to execute \n", time_list);

    return (0);
}
