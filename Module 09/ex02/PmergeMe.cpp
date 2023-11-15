#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe( char **argv )
{
    if(argvToVector( argv ))
        return ;
    print_vector( vector );
    std::cout << std::endl;
}

//-----------------------------Convert and Print---------------------------------------------------

//With error handling
bool PmergeMe::ft_isnum(char *str)
{
    int i;

    i = 0;
    if(str[i] == '-')
        i = 1;
    for ( ; str[i]; i++)
        if( !( std::isdigit(str[i]) ) )
        {
            std::cout << "Error" << std::endl << "It is not an integer: " << str << std::endl;
            return ( false );
        }
    return ( true );
}

//returns 1 if it fails overflow or no num
int PmergeMe::argvToVector( char **argv )
{
    int num;
    std::stringstream ss;

    for(int i = 1; argv[i]; i++)
    {
        if( ft_isnum(argv[i]) == false )
            return (1);
        std::stringstream ss(argv[i]);
        ss >> num;
        if(ss.fail())
        {
            std::cout << "Error" << std::endl << "Overflow" << std::endl;
            return (1);
        }
        vector.push_back(num);
    }
    return (0);
}

void PmergeMe::print_vector( const std::vector<int> &v )
{
    for( size_t i = 0; i < v.size(); i++ )
    {
        std::cout << v[i];
        if(i != v.size() - 1)
            std::cout << " ";
    }
}
