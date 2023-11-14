#include "PmergeMe.hpp"

PmergeMe::PmergeMe( char **argv )
{
    argvToVector( argv );
}

//With error handling
int PmergeMe::argvToVector( char **argv )
{
    long num = 0;
    for( int i = 1; argv[i]; i++ )
    {
        if( argv[i][0] == '0' && argv[i][1] == 0 ){
            vector.push_back(0);
            continue ;
        }
        if( argv[i][0] == '-' && argv[i][1] == '1' && argv[i][2] == 0 ){
            vector.push_back(-1);
            continue ;
        }
        num = std::atol(argv[i]);
        if( num == 0 || num == -1)
        {
            std::cout << "Error: wrong input" << std::endl;
            return 1;
        }
        else
            vector.push_back(num);
    }
    return (0);
}