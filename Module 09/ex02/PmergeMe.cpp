# include "PmergeMe.hpp"
# include <sstream>

PmergeMe::PmergeMe( char **argv )
{
    if(argvToVector( argv ))
        return ;
    vv.push_back(vector);
    print_vv( vv );
    ford_johnson_vector( vv, 1 );
    print_vv( vv );

    binary_search( vv[0], 0, vv[0].size(), 10);
}

void swap_pairs( std::vector< std::vector<int> > &pairs )
{
    for( size_t y = 0; y < pairs.size() - 1; y += 2 )
    {
        /* std::cout << "y = " << y << " " << pairs[y][0] << std::endl;
        std::cout << "y + 1 = " << pairs[y + 1][0] << std::endl; */
        if( pairs[y][0] < pairs[y + 1][0] )
        {
            /* std::cout << "y = " << y << std::endl; */
            std::iter_swap( pairs.begin() + y, pairs.begin() + y + 1);
        }
    }
}

void split_vector_into_chains( std::vector< std::vector<int> > &pairs )
{
    std::vector<int> main_chain;
    std::vector<int> second_chain;

    //create the 2 chains from the pairs
    for( size_t element = 0; element < pairs[0].size(); element += 2 )
    {
        main_chain.push_back(pairs[0][element]);

        /* if(x + 1 < pairs[0].size()) USELESS BECAUSE ALWAYS EVEN */

        second_chain.push_back(pairs[0][element + 1]);
    }
    /* if( main_chain.size() > second_chain.size() ) USELESS BECAUSE ALWAYS EVEN
    {
        second_chain.push_back( main_chain.back() );
        main_chain.erase( main_chain.end() - 1);
    } */
    pairs.push_back( main_chain );
    pairs.push_back( second_chain );
    pairs.erase( pairs.begin() );
}

void PmergeMe::join_pairs_together( std::vector< std::vector<int> > &pairs )
{
    for(size_t y = 0; y < pairs.size() - 1; y++)
    {
        /* std::vector<int> main_chain(pairs[0]);

        for (size_t i = 2; i < main_chain.size(); i += 1)
            main_chain.erase(main_chain.begin() + i);

        binary_search(main_chain, 0, main_chain.size(), pairs[1][0]);
        if(insert_pos == 0)
            insert_pos = 0;
        else if(insert_pos >= (int)main_chain.size())
            insert_pos = pairs[0].size();
        else
            insert_pos = insert_pos * 2;

        pairs[0].insert(pairs[0].begin() + insert_pos, pairs[1].begin(), pairs[1].end());
        pairs.erase(pairs.begin() + 1); */
        while( pairs[y + 1].empty() == false )
        {
            pairs[y].push_back(pairs[y + 1][0]);
            pairs[y + 1].erase(pairs[y + 1].begin());
        }
        if( pairs[ y + 1 ].empty() == true )
            pairs.erase( pairs.begin() + ( y + 1 ) );

        /* std::cout << std::endl << "size = " << pairs.size() << std::endl;
        std::cout << "y = " << y << std::endl;
        print_vv( pairs );
        std::cout << "----------------------" << std::endl; */
    }
}

//-----------------------------Ford Johnson Vector-------------------------------------------------
void PmergeMe::ford_johnson_vector( std::vector< std::vector<int> > &pairs, int pair_size )
{
    //if one pair is bigger than the other swap it
    /* if( vector.size() == 1 )
        return ; */

    if( pairs.size() == 1 )
    {
        /* split_vector_into_chains( pairs ); */
        return ;
    }
    swap_pairs( pairs );


    std::cout << "----------------------" << std::endl;
    print_vv( pairs );

    pair_size = pairs[0].size();
    join_pairs_together( pairs );

    //to know how big the pairs should be when joining together

    // delete if last row is empty

    if( pairs[ pairs.size() - 1 ].empty() == true )
        pairs.erase( pairs.begin() + pairs.size() - 1 );

    // if pairs size > 1 do recursion
    ford_johnson_vector( pairs, pair_size );
    
    //------------------------------------------------------------------------------------------------------binary_search
    std::cout << "===============================" << std::endl;
    print_vv(pairs);
    std::vector<int> main_chain;
    std::vector<int> vanilla_mainchain;

    int jk_insert_order[] = { 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525 };
    int n = sizeof(jk_insert_order) / sizeof(jk_insert_order[0]);
 
    std::vector<int> jk_order(jk_insert_order, jk_insert_order + n);
    std::vector<int>::iterator jk_order_itr = jk_order.begin();

    for ( std::size_t y = 0; y < pairs.size(); y++ )
    {
        main_chain.push_back(pairs[y][0]);
    }
    vanilla_mainchain.push_back(main_chain[0]);
    std::size_t yy = 1;
    jk_order_itr++;
    /* if( yy > main_chain.size() )
        yy = main_chain.size(); */
    for ( ; yy < pairs.size(); )
    {
        /* if( y == (size_t)jk_order_itr[0] )
        { */
            /* vanilla_mainchain.push_back(main_chain[y]); */
            std::cout << "=========asdsad============" << std::endl;
            if(yy != 1)
                vanilla_mainchain.insert( vanilla_mainchain.end(), main_chain.rend() - (((jk_order_itr - 1)[0])), main_chain.rend() - (((jk_order_itr - 2)[0])) );
            yy = jk_order_itr[0];
            jk_order_itr++;
            if( (jk_order_itr - 1)[0] > (int)pairs.size() )
            {
                std::cout << "========= x ===========" << ((jk_order_itr)[0]) << std::endl;     //last element
                std::cout << "========= y ===========" << ((jk_order_itr - 2)[0]) << std::endl;
                vanilla_mainchain.insert( vanilla_mainchain.end(), ( main_chain.rbegin()), main_chain.rend() - (((jk_order_itr - 2)[0])) );
                break;
            }
        /* } */
        /* else
        {
            vanilla_mainchain.push_back(pairs[y - 1][0]);
            y--;
        } */
    }
    std::cout << "=========MAIN CHAIN============" << std::endl;
    print_vector(vanilla_mainchain);
    /* vanilla_mainchain = main_chain; */
    std::cout << std::endl << "===============================" << std::endl;
    /* if(pairs.back().size() == 2)
        return ; */
    std::cout << "pair size = " << pair_size << std::endl;

    int pair_end = 2;
    int pair_start = 1;
    std::vector< std::vector<int> >::iterator pairs_mainchain_itr = pairs.begin();
    

    for( size_t y = 0; y < vanilla_mainchain.size(); y++ )
    {
        
        pairs_mainchain_itr = pairs.begin() + (std::find(main_chain.begin(), main_chain.end(), vanilla_mainchain[y]) - main_chain.begin());
        std::cout << pairs_mainchain_itr[0][0] << std::endl;
            if(pairs_mainchain_itr[0].size() < 3 && pair_size > 1)
                continue ; 


        /* int insert_number; */

        /* pairs_mainchain_itr = pairs.begin();
        if(jk_insert_order[ y ] > (int)vanilla_mainchain.size())
            insert_number =  vanilla_mainchain.back();
        else
            insert_number = vanilla_mainchain[ jk_insert_order[ y ] - 1 ];

        while( pairs_mainchain_itr->front() != insert_number )
            pairs_mainchain_itr++; */


        /* std::cout << "i = " << vanilla_mainchain[ jk_insert_order[ y ] - 1 ] << std::endl; */
        /* pairs_mainchain_itr = pairs.begin() + jk_insert_order[y] - 1; */
        // Now insert 4 3 or 10 9 8 7.. jacob stahl
        /* int i;
        if( jk_insert_order[ y ] == 1)
            i = 0;
        else
            i = jk_insert_order[ y - 1 ]; */
        /* std::cout << "                  a                   "<< jk_insert_order[ y ] << std::endl; */
        /* for ( ; i < jk_insert_order[ y ] && i < (int)vanilla_mainchain.size(); i++)
        { */
            get_pair_size( pairs_mainchain_itr, pair_size, pair_start, pair_end );

            std::cout << "pair start = = = = = = = =             " << pair_start << std::endl;
            binary_search(main_chain, 0, main_chain.size(), pairs_mainchain_itr[0][pair_start]);

            // create vector(pairs) of the insert elements and erase tham from their old place
            std::vector<int> new_elements_to_insert( pairs_mainchain_itr->begin() + pair_start, pairs_mainchain_itr->begin() + pair_end );
            pairs_mainchain_itr->erase( pairs_mainchain_itr->begin() + pair_start, pairs_mainchain_itr->begin() + pair_end );
        
            /* std::cout << pairs_mainchain_itr[0][pair_start] << std::endl; */

            main_chain.insert( main_chain.begin() + insert_pos, pairs_mainchain_itr[0][pair_start] );
            pairs.insert( pairs.begin() + insert_pos, new_elements_to_insert );

            /* pairs_mainchain_itr = pairs.begin(); */
            
            /* if(jk_insert_order[ y ] > (int)vanilla_mainchain.size())
                insert_number =  vanilla_mainchain.back();
            else
                insert_number = vanilla_mainchain[ jk_insert_order[ y - i ] - 1 ];

            while( pairs_mainchain_itr->front() != insert_number )
                pairs_mainchain_itr++;

        } */
        
    }
    std::cout << std::endl << "===[[]]============================" << std::endl;
}

void PmergeMe::get_pair_size( std::vector< std::vector<int> >::iterator pairs_mainchain_itr, int pair_size, int &pair_start, int &pair_end )
{
    if( pair_size > 1 )
    {
        pair_end = pairs_mainchain_itr[0].size();
        /* if( pair_end > (int)pairs_mainchain_itr[0].size() )
            pair_end = pairs_mainchain_itr[0].size(); */

        pair_start = pair_size;
        if( pair_start > (int)pairs_mainchain_itr[0].size() )
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
        // PUSH BACK INTO PAIRS
        /* if( i % 2 == 0 )
        {
            if( vector.size() == 2 && vector[0] < vector[1] )
                std::iter_swap( vector.begin(), vector.begin() + 1 );
            vv.push_back(vector);
            vector.clear();
        }
        else
            vector.push_back(num); */
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
