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

int main ( int argc, char **argv )
{
    if(argc == 1)
        return 1;
    std::vector<int> input;
    if(argvToVector( argv, input ))
        return 1;
    PmergeMe sort( input );
    return 0;
}