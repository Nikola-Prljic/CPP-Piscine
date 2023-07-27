/* #include "PmergeMe.hpp" */
#include <stdlib.h>
#include <iostream>
#include <vector>

int argvToVector( char **argv, std::vector<int> &input )
{
    for( int i = 1; argv[i]; i++ )
        input.push_back(std::atoi(argv[i]));
    return 0;
}

int main ( int argc, char **argv )
{
    if(argc == 1)
        return 1;
    std::vector<int> input;
    argvToVector( argv, input );
    std::cout << input[1];
    /* PmergeMe sort( argv ); */
    return 0;
}