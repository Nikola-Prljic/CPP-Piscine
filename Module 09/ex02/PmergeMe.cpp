#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe( char **argv )
{
    if(argvToVector( argv ))
        return ;
    vv.push_back(vector);

    print_vv( vv );

    ford_johnson_vector( vv, 0 );

    //print_vector( vector );
    print_vv( vv );
}

//-----------------------------Ford Johnson Vector-------------------------------------------------
void PmergeMe::ford_johnson_vector( std::vector< std::vector<int> > &v_v, int i )
{
    size_t x = 0;
    for(size_t y = 0; y < v_v.size() - 1; y++)
    {

        /* if( y + 1 > v_v.size() )
            continue ; */

        /* if( v_v[y + 1].empty() == false)
        {
            v_v[y].push_back(v_v[y + 1][x]);
            v_v[y + 1].erase(v_v[y + 1].begin());
        }
        if(v_v[y + 1].empty() == false)
        {
            v_v[y].push_back(v_v[y + 1][x]);
            v_v[y + 1].erase(v_v[y + 1].begin());
        } */
        while(v_v[y + 1].empty() == false)
        {
            v_v[y].push_back(v_v[y + 1][x]);
            v_v[y + 1].erase(v_v[y + 1].begin());
        }
        if(v_v[ y + 1 ].empty() == true)
            v_v.erase( v_v.begin() + (y + 1) );
        std::cout << std::endl << "size = " << v_v.size() << std::endl;
        std::cout << "y = " << y << std::endl;
        print_vv( v_v );
        std::cout << "----------------------" << std::endl;
        /* if( v_v[y + 1].empty() == true )
            v_v.erase( v_v.begin() + ( y + 1 ) ); */
        //x += 2;
    }

    // delete if last row is empty
    if(v_v[ v_v.size() - 1 ].empty() == true)
        v_v.erase( v_v.begin() + v_v.size() - 1 );
    /* return ; */
    //if(v[i] < v[i + 1] && (size_t)i < v.size() / 2)
    //    iter_swap(v.begin() + i, v.begin() + i + 1);
    //if(v[i + 2] < v[i + 3])
    //    iter_swap(v.begin() + i + 2, v.begin() + i + 3);
    i++;
    std::cout << "a";
    if(v_v.size() == 1)
        return ;
    ford_johnson_vector( v_v, i);
    return ;
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

        // PUSH BACK INTO PAIRS
        if( i % 2 == 0 )
        {
            vector.push_back(num);
            vv.push_back(vector);
            vector.clear();
        }
        else
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

void PmergeMe::print_vv( const std::vector< std::vector<int> > &v )
{
    for( size_t i = 0; i < v.size(); i++)
    {
        print_vector( v[i] );
        std::cout << std::endl;
    }
}
