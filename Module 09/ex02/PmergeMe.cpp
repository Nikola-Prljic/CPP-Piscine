#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe( char **argv )
{
    if(argvToVector( argv ))
        return ;
    vv.push_back(vector);

    /* print_vv( vv ); */

    ford_johnson_vector( vv );

    //print_vector( vector );
    print_vv( vv );
}

void swap_pairs( std::vector< std::vector<int> > &v_v )
{
    for( size_t y = 0; y + 1 < v_v.size(); y += 2 )
        if( v_v[y][0] < v_v[y + 1][0] )
            std::iter_swap( v_v.begin() + y, v_v.begin() + y + 1);
}

void split_vector_into_pairs( std::vector< std::vector<int> > &v_v )
{
    size_t y = 1;
    std::vector<int> v;
    for( size_t x = 0; x < v_v[0].size(); x += 2 )
    {
        v.push_back(v_v[0][x]);
        if(x + 1 < v_v[0].size())
            v.push_back(v_v[0][x + 1]);
        v_v.push_back(v);
        v.clear();
        y++;
    }
    v_v.erase( v_v.begin() );
}

//-----------------------------Ford Johnson Vector-------------------------------------------------
void PmergeMe::ford_johnson_vector( std::vector< std::vector<int> > &v_v )
{
    swap_pairs(v_v);
    /* return ; */

    size_t x = 0;
    for(size_t y = 0; y < v_v.size() - 1; y++)
    {
        while(v_v[y + 1].empty() == false)
        {
            v_v[y].push_back(v_v[y + 1][x]);
            v_v[y + 1].erase(v_v[y + 1].begin());
        }
        if(v_v[ y + 1 ].empty() == true)
            v_v.erase( v_v.begin() + ( y + 1 ) );


        std::cout << std::endl << "size = " << v_v.size() << std::endl;
        std::cout << "y = " << y << std::endl;
        print_vv( v_v );
        std::cout << "----------------------" << std::endl;

    }

    // delete if last row is empty
    if(v_v[ v_v.size() - 1 ].empty() == true)
        v_v.erase( v_v.begin() + v_v.size() - 1 );

    // if size of v of v is 1 end recursive
    if(v_v.size() == 1)
    {
        split_vector_into_pairs( v_v );
        return ;
    }

    ford_johnson_vector( v_v );
}




//-----------------------------Convert and Print---------------------------------------------------

//With error handling
bool PmergeMe::ft_isnum(char *str)
{
    int i = 0;

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
            if( vector.size() == 2 && vector[0] < vector[1] )
                std::iter_swap( vector.begin(), vector.begin() + 1 );
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
