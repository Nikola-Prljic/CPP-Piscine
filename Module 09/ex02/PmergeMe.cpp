# include "PmergeMe.hpp"
# include <sstream>

PmergeMe::PmergeMe( char **argv )
{
    if(argvToVector( argv ))
        return ;
    vv.push_back(vector);
    print_vv( vv );
    create_jacob_numbers();
    ford_johnson_vector( vv, 1 );
    print_vv( vv );
    binary_search( vv[0], 0, vv[0].size(), 10);
}

void swap_pairs( std::vector< std::vector<int> > &pairs )
{
    for( size_t y = 0; y < pairs.size() - 1; y += 2 )
        if( pairs[y][0] < pairs[y + 1][0] )
            std::iter_swap( pairs.begin() + y, pairs.begin() + y + 1);
}

void split_vector_into_chains( std::vector< std::vector<int> > &pairs )
{
    std::vector<int> main_chain;
    std::vector<int> second_chain;

    //create the 2 chains from the pairs
    for( size_t element = 0; element < pairs[0].size(); element += 2 )
    {
        main_chain.push_back(pairs[0][element]);
        second_chain.push_back(pairs[0][element + 1]);
    }
    pairs.push_back( main_chain );
    pairs.push_back( second_chain );
    pairs.erase( pairs.begin() );
}

void PmergeMe::join_pairs_together( std::vector< std::vector<int> > &pairs )
{
    for(size_t y = 0; y < pairs.size() - 1; y++)
    {
        while( pairs[y + 1].empty() == false )
        {
            pairs[y].push_back(pairs[y + 1][0]);
            pairs[y + 1].erase(pairs[y + 1].begin());
        }
        if( pairs[ y + 1 ].empty() == true )
            pairs.erase( pairs.begin() + ( y + 1 ) );
    }
}

//-----------------------------Ford Johnson Vector-------------------------------------------------
void PmergeMe::ford_johnson_vector( std::vector< std::vector<int> > &pairs, int pair_size )
{
    if( pairs.size() == 1 )
        return ;
    //if one pair is bigger than the other swap it
    swap_pairs( pairs );
    pair_size = pairs[0].size();
    
    //join pairs together until a sorted main chain
    join_pairs_together( pairs );

    // delete if last row is empty
    if( pairs[ pairs.size() - 1 ].empty() == true )
        pairs.erase( pairs.begin() + pairs.size() - 1 );

    // if pairs size > 1 do recursion
    ford_johnson_vector( pairs, pair_size );

    std::vector<int> main_chain, vanilla_mainchain;

    for ( std::size_t y = 0; y < pairs.size(); y++ )
        main_chain.push_back(pairs[y][0]);

    //            --------          create insert oreder           -----------
    vanilla_mainchain = create_insert_oreder( pairs, main_chain );
    insert_into_main_chain(pairs, vanilla_mainchain, main_chain, pair_size);
}

void PmergeMe::create_jacob_numbers()
{
    int jk_insert_order[] = { 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525 };
    int n = sizeof(jk_insert_order) / sizeof(jk_insert_order[0]);
    std::vector<int> jk_order_tmp(jk_insert_order, jk_insert_order + n);
    jk_order = jk_order_tmp;
}

std::vector<int> PmergeMe::create_insert_oreder( std::vector< std::vector<int> > &pairs, std::vector<int> main_chain )
{
    std::size_t yy = 1;
    std::vector<int> vanilla_mainchain;
    std::vector<int>::iterator jk_order_itr = jk_order.begin();

    vanilla_mainchain.push_back(main_chain[0]);
    jk_order_itr++;
    for ( ; yy < pairs.size(); )
    {
        if(yy != 1)
            vanilla_mainchain.insert( vanilla_mainchain.end(), main_chain.rend() - (((jk_order_itr - 1)[0])), main_chain.rend() - (((jk_order_itr - 2)[0])) );
        yy = jk_order_itr[0];
        jk_order_itr++;
        if( (jk_order_itr - 1)[0] >= (int)pairs.size() )
        {
            vanilla_mainchain.insert( vanilla_mainchain.end(), ( main_chain.rbegin()), main_chain.rend() - (((jk_order_itr - 2)[0])) );
            break;
        }
    }
    return (vanilla_mainchain);
}

void PmergeMe::insert_into_main_chain(std::vector< std::vector<int> > &pairs, std::vector<int> vanilla_mainchain, std::vector<int> main_chain, int pair_size)
{
    int pair_end = 2;
    int pair_start = 1;
    std::vector< std::vector<int> >::iterator pairs_mainchain_itr = pairs.begin();

    for( size_t y = 0; y < vanilla_mainchain.size(); y++ )
    {
        pairs_mainchain_itr = pairs.begin() + (std::find(main_chain.begin(), main_chain.end(), vanilla_mainchain[y]) - main_chain.begin());

        if(pairs_mainchain_itr[0].size() < 3 && pair_size > 1)
            continue ;

        get_pair_size( pairs_mainchain_itr, pair_size, pair_start, pair_end );
        binary_search(main_chain, 0, main_chain.size(), pairs_mainchain_itr[0][pair_start]);

        std::vector<int> new_elements_to_insert( pairs_mainchain_itr->begin() + pair_start, pairs_mainchain_itr->begin() + pair_end );
        pairs_mainchain_itr->erase( pairs_mainchain_itr->begin() + pair_start, pairs_mainchain_itr->begin() + pair_end );
    
        main_chain.insert( main_chain.begin() + insert_pos, pairs_mainchain_itr[0][pair_start] );
        pairs.insert( pairs.begin() + insert_pos, new_elements_to_insert );
    }
}

void PmergeMe::get_pair_size( std::vector< std::vector<int> >::iterator pairs_mainchain_itr, int pair_size, int &pair_start, int &pair_end )
{
    if( pair_size > 1 )
    {
        pair_end = pairs_mainchain_itr[0].size();
        pair_start = pair_size;
        if( pair_start >= (int)pairs_mainchain_itr[0].size() )
            pair_start = pairs_mainchain_itr[0].size() / 2 ;
        if( pair_start % 2 != 0 )
            pair_start++;
    }
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
            std::cout << "Error" << std::endl << "input is not an integer: " << str << std::endl;
            return ( false );
        }
    return ( true );
}

void PmergeMe::binary_search( std::vector<int> main_chain, int start, int end, int num) 
{
    int range = start + ( ( end - start ) / 2 );
    if( main_chain.empty() == true )
        return ;
    if( range >= (int)main_chain.size() )
    {
        insert_pos = (int)main_chain.size();
        std::cout << num << " an Position " << (int)main_chain.size() << " enthalten." << std::endl;
        return ;
    }
    if (num > main_chain[range]) 
    {
        /* System.out.println(start + " " + end + " " + range); */
        binary_search(main_chain, range + 1, end, num);
    }
    else if (num < main_chain[range] && start != range)
        binary_search(main_chain, start, range - 1, num);
    else if(num == main_chain[range])
    {
        insert_pos = range;
        std::cout << num << " an Position " << range << " enthalten." << std::endl; 
    }
    else
    {
        insert_pos = range;
        std::cout << num << " nicht im Array enthalten." << range << std::endl;
    }
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
        if( ss.fail() )
        {
            std::cout << "Error" << std::endl << "Overflow" << std::endl;
            return (1);
        }
        vector.push_back(num);
        vv.push_back(vector);
        vector.clear();
    }
    if( vv.size() % 2 != 0 )
    {
        odd_last_element = vv.back()[0];
        vv.erase( vv.end() - 1 );
        vector_is_even = false;
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
