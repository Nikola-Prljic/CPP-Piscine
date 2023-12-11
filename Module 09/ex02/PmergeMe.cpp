# include "PmergeMe.hpp"
# include <sstream>

PmergeMe::PmergeMe( char **argv ) : vector_is_even(true)
{
    odd_last_element = 42;
    if(argvToVector( argv ))
        return ;
    /* pairs.push_back(vector); */
   /*  print_vv( pairs ); */

    create_jacob_numbers();
    ford_johnson_vector( 1 );
    /* std::cout << std::endl; */

   /*  print_vv( pairs ); */
    /* std::cout << "-------------deque--------------" << std::endl; */

    argvTodeque( argv );
    fordJohnsonDequeSorting( 1 );
}

void PmergeMe::swapPairsIfGreater( std::vector< std::vector<int> > &pairs )
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

void PmergeMe::join_pairs_together()
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
void PmergeMe::ford_johnson_vector( int pair_size )
{
    if( pairs.size() == 1 )
        return ;
    //if one pair is bigger than the other swap it
    /* print_vv(pairs); */
    /* std::cout << "-----------end_________" << std::endl; */
    swapPairsIfGreater( pairs );
    pair_size = pairs[0].size();

    //join pairs together until a sorted main chain
    join_pairs_together();

    // delete if last row is empty
    if( pairs[ pairs.size() - 1 ].empty() == true )
        pairs.erase( pairs.begin() + pairs.size() - 1 );

    // if pairs size > 1 do recursion
    ford_johnson_vector( pair_size );

    std::vector<int> main_chain, vanilla_mainchain;
 
    for ( std::size_t y = 0; y < pairs.size(); y++ )
        main_chain.push_back( pairs[y][0] );
    if(vector_is_even == false && pair_size == 1)
    {
        main_chain.push_back( odd_last_element );
        pairs.push_back( std::vector<int>( 1, odd_last_element ) );
    }
    //            --------          create insert oreder           -----------
    vanilla_mainchain = create_insert_oreder( main_chain );

    //            --------          insert pairs into mainchain          -----------
    insert_into_main_chain( vanilla_mainchain, main_chain, pair_size);
}

void PmergeMe::create_jacob_numbers()
{
    int jk_insert_order[] = { 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525 };
    int n = sizeof(jk_insert_order) / sizeof(jk_insert_order[0]);

    std::vector<int> jk_order_tmp(jk_insert_order, jk_insert_order + n);
    jk_order = jk_order_tmp;
}

void PmergeMe::insert_into_main_chain( const std::vector<int> &vanilla_mainchain, std::vector<int> &main_chain, int pair_size)
{
    /* std::cout << "pair_size = " << pair_size << std::endl; */
    int pair_end = 2;
    int pair_start = 1;
    int size_main_chain;
    bool odd_is_inserted = false;
    std::vector< std::vector<int> >::iterator pairs_mainchain_itr = pairs.begin();
    for( size_t y = 0; y < vanilla_mainchain.size(); y++ )
    {
        size_main_chain = main_chain.size();
        if(odd_is_inserted == false && vector_is_even == false && pair_size == 1)
            size_main_chain--;

        pairs_mainchain_itr = pairs.begin() + (std::find(main_chain.begin(), main_chain.end(), vanilla_mainchain[y]) - main_chain.begin());

        if(pairs_mainchain_itr[0].size() < 3 && pair_size > 1)
            continue ;

        get_pair_size( pairs_mainchain_itr, pair_size, pair_start, pair_end );
        customBinarySearch( main_chain, 0, size_main_chain, pairs_mainchain_itr[0][pair_start] );

        std::vector<int> new_elements_to_insert( pairs_mainchain_itr->begin() + pair_start, pairs_mainchain_itr->begin() + pair_end );


        /* std::cout << "new_elements_to_insert = ";
        print_vector(new_elements_to_insert);
        std::cout << std::endl; */

        main_chain.insert( main_chain.begin() + insert_pos, pairs_mainchain_itr[0][pair_start] );

        /* std::cout << "main_chain = ";
        print_vector(main_chain);
        std::cout << std::endl; */
    
        if( pairs_mainchain_itr[0].size() == 1 && vector_is_even == false)
        {
            main_chain.erase( main_chain.end() - 1 );
            pairs.erase( pairs_mainchain_itr );
            odd_is_inserted = true;
        }
        else
            pairs_mainchain_itr->erase( pairs_mainchain_itr->begin() + pair_start, pairs_mainchain_itr->begin() + pair_end );
    
        pairs.insert( pairs.begin() + insert_pos, new_elements_to_insert );
    
    }
    /* std::cout << "------------------" << std::endl;
    print_vv(pairs);
    std::cout << "------------------" << std::endl;
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl; */
}

void PmergeMe::get_pair_size( const std::vector< std::vector<int> >::const_iterator &pairs_mainchain_itr, const int &pair_size, int &pair_start, int &pair_end )
{
    if( pair_size < 2 )
    {
        if( pairs_mainchain_itr[0].size() == 1 )
        {
            pair_start = 0;
            pair_end = 1;
        }
        else
        {
            pair_start = 1;
            pair_end = 2;
        }
        return ;
    }
    pair_end = pairs_mainchain_itr[0].size();
    pair_start = pair_size;
    if( pair_start >= (int)pairs_mainchain_itr[0].size() )
        pair_start = pairs_mainchain_itr[0].size() / 2 ;
    if( pair_start % 2 != 0 )
        pair_start++;
}

//-----------------------------Convert and Print---------------------------------------------------

//With error handling
bool PmergeMe::ft_isnum( const char *str)
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

void PmergeMe::customBinarySearch( const std::vector<int> &main_chain, int start, int end, int num) 
{
    int range = start + ( ( end - start ) / 2 );
    if( main_chain.empty() == true )
        return ;
    if( range >= (int)main_chain.size() )
    {
        insert_pos = (int)main_chain.size();
        return ;
    }
    if (num > main_chain[range]) 
        customBinarySearch(main_chain, range + 1, end, num);
    else if (num < main_chain[range] && start != range)
        customBinarySearch(main_chain, start, range - 1, num);
    else if(num == main_chain[range])
        insert_pos = range;
    else
        insert_pos = range;
}


int convert_number( char *argv, std::vector<int> num_tmp, int &num )
{
    std::stringstream ss(argv);
    ss >> num;
    if( ss.fail() )
    {
        std::cout << "Error" << std::endl << "Overflow" << std::endl;
        return (1);
    }
    if( std::find( num_tmp.begin(), num_tmp.end(), num) != num_tmp.end())
    {
        std::cout << "Error" << std::endl << "No double numbers" << std::endl;
        return (1);
    }
    return (0);
}

//returns 1 if it fails overflow or no num
int PmergeMe::argvToVector( char **argv )
{
    int num;
    std::vector<int> vector;

    for(int i = 1; argv[i]; i++)
    {

        if( ft_isnum( argv[i] ) == false )
            return (1);

        if( convert_number( argv[i], input_original, num ) )
            return (1);

        input_original.push_back(num);
        vector.push_back(num);
        pairs.push_back(vector);
        vector.clear();
        if(i > 5000)
        {
            std::cout << "Error" << std::endl << "Not more than 5000 numbers" << std::endl;
            return (1);
        }
    }
    if( pairs.size() % 2 != 0 )
    {
        odd_last_element = pairs.back()[0];
        pairs.erase( pairs.end() - 1 );
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

std::vector< std::vector<int> > PmergeMe::getPairs() { return pairs; }

std::vector<int> PmergeMe::getInput_original() { return input_original; }




// -------------------------------------------------------------------------------------------------- //
// -----------------------------    FORD JOHNSON deque SORTING    ----------------------------------- //
// -------------------------------------------------------------------------------------------------- //




int PmergeMe::argvTodeque( char **argv )
{
    int num;

    for(int i = 1; argv[i]; i++)
    {
        if( ft_isnum( argv[i] ) == false )
            return (1);
        std::stringstream ss(argv[i]);
        ss >> num;
        if( ss.fail() )
        {
            std::cout << "Error" << std::endl << "Overflow" << std::endl;
            return (1);
        }
        deque.push_back(num);
    }
    if(deque.size() % 2 != 0)
    {
        odd_last_element = deque.back();
        deque.pop_back();
        vector_is_even = false;
    }
    return (0);
}

void PmergeMe::swapElementsInRange( deque_itr pair_start, deque_itr pair_end, deque_itr next_pair_start, deque_itr pair_end_next )
{
    /* int tmp2;
    if(pair_start == pair_end)
    {
        tmp2 = *pair_start;
        *pair_start = *next_pair_start;
        *next_pair_start = tmp2;
        pair_start++;
        next_pair_start++;
        return ;
    } */
    /* for( ;next_pair_start != deque.end() && pair_start != pair_end + 1; )
    { */

    bool is_end = false;
    if( pair_end_next + 1 == deque.end() )
        is_end = true;
    int insert_pos_num = *(pair_end_next + 1);

    (void)next_pair_start; // RM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    /* std::cout << "ACHTUNG !!!!!!!!!!!!!" << std::endl; */
    std::deque<int> tmp( pair_start, pair_end + 1 );
    /* print_deque(tmp); */
    /* std::cout << *pair_end_next << "ACHTUNG !!!!!!!!!!!!!" << std::endl; */
    deque.erase( pair_start, pair_end + 1 );

    if(is_end == false)
        pair_end_next = std::find(deque.begin(), deque.end(), insert_pos_num);
    else
        pair_end_next = deque.end();
    deque.insert( pair_end_next, tmp.begin(), tmp.end() );
    /* print_deque(deque); */
    /* exit(1); */
    /* } */
}

void PmergeMe::swapPairsIfGreater( int steps )
{
    deque_itr pair_start = deque.begin();
    deque_itr pair_end = pair_start + (steps - 1);
    deque_itr pair_start_next = pair_end + 1;
    deque_itr pair_end_next = pair_start_next + (steps - 1);
    /* std::cout << "-> pstart = " << *pair_start << std::endl;
    std::cout << "end = " << *pair_end << std::endl;
    std::cout << "npstart = " << *pair_start_next << std::endl;
    std::cout << "-> npend = " << *pair_end_next << std::endl;
    std::cout << "----------steps = " << steps << std::endl; */
    if(steps * 2 > (int)deque.size())
        pair_end_next = deque.end() - 1;
    for( std::size_t i = steps; i < deque.size() && pair_start != deque.end() && pair_start_next != deque.end(); )
    {
        i += steps;
        // (std::size_t)(steps * 2) < deque.size() strange ???????
        if( *pair_start < *pair_start_next && (std::size_t)(steps * 2) < deque.size())
        {
            if(steps == 1)
                std::iter_swap(pair_start, pair_start_next);
            else
                swapElementsInRange( pair_start, pair_end, pair_start_next, pair_end_next );
        }
        pair_start = deque.begin() + i;
        pair_end = pair_start + (steps - 1);
        pair_start_next = pair_end + 1;
        pair_end_next = pair_start_next + (steps - 1);
        i += steps;
        if(i + steps >= deque.size())
        {
            pair_end_next = deque.end() - 1;
        }

        /* std::cout << "-> pstart = " << *pair_start << std::endl;
        std::cout << "end = " << *pair_end << std::endl;
        std::cout << "npstart = " << *pair_start_next << std::endl;
        std::cout << "-> npEND = " << *pair_end_next << std::endl; */
    }
    /* std::cout << "+++++++++++" << steps << std::endl; */
}

std::deque<int> PmergeMe::findElementsToInsert( const int &steps )
{
    std::deque<int> elements_to_insert;
    std::deque<int>::iterator deque_main_chain_itr = deque_main_chain.begin();
    std::deque<int>::iterator deque_next_pair;

    while( deque_main_chain_itr != deque_main_chain.end() )
    {
        std::deque<int>::iterator deque_first_pair = std::find(deque.begin(), deque.end(), *deque_main_chain_itr);
        /* if(*deque_first_pair == odd_last_element && steps == 2)
        {
            elements_to_insert.push_back( odd_last_element );
            return (elements_to_insert);
        } */
        if( (deque_main_chain_itr + 1) != deque_main_chain.end() )
        {
            deque_next_pair = std::find(deque.begin(), deque.end(), *(deque_main_chain_itr + 1) );
        }
        else
        {
            deque_next_pair = deque.end();
        }

/*         std::cout << "deque_first_pair = " << *deque_first_pair << " || deque_next_pair = " << *deque_next_pair << std::endl;
        std::cout << "deque_next_pair = " << std::distance(deque_first_pair, deque_next_pair)<< std::endl;
   */      
        if( *deque_main_chain_itr == *deque_first_pair && std::distance(deque_first_pair, deque_next_pair) > steps / 2)
        {
            elements_to_insert.push_back( *(deque_first_pair + steps / 2));
        }
        deque_main_chain_itr++;
    }
    if(steps == 2 && vector_is_even == false)
    {
/*         std::cout << "-------------------------------asdasdasdasdasdasd--------------------------" << std::endl;
 */     
        deque.push_back(odd_last_element);
        /* deque_main_chain.push_back(odd_last_element); */
        elements_to_insert.push_back(odd_last_element);
    }
    return (elements_to_insert);
}

void PmergeMe::insertPairsIntoMainChain( const int &steps )
{
    /* std::cout << "steps = " << steps << std::endl; */
    /* deque_itr pair_start = deque.begin();
    deque_itr pair_end = deque.begin() + ( steps - 1 ); */
    deque_itr pair_start_next = deque.begin() + steps / 2;
    /* std::deque<int> main_chain; */
    std::size_t pair_size = 0;
    /* for( std::size_t i = 0; i < deque.size(); i += steps )
        main_chain.push_back(deque[i]); */
    /* std::cout << "deque_main_chain = ";
    print_deque(deque_main_chain); */
    std::deque<int> vanilla_main_chain = findElementsToInsert( steps );
    /* std::cout << "insert order = ";
    print_deque(vanilla_main_chain); */

    vanilla_main_chain = create_insert_oreder( vanilla_main_chain );
    /* vanilla_main_chain = main_chain; */
    std::deque<int>::iterator vanilla_main_chain_itr = vanilla_main_chain.begin();
    /* std::cout << "main chain = ";
    print_deque(deque_main_chain); */
    std::deque<int>::iterator deque_main_chain_itr = deque_main_chain.begin();
    /* print_deque(deque); */
    std::deque<int>::iterator deque_insert_pos = deque.begin();
    for( std::size_t i = 0; i < deque.size() && vanilla_main_chain_itr != vanilla_main_chain.end(); i += steps )
    {
        pair_start_next = std::find(deque.begin(), deque.end(), *vanilla_main_chain_itr);
        /* if( steps > 2 || vector_is_even == true || *pair_start_next == odd_last_element )
        {
            if(*pair_start_next == odd_last_element)
            {
                vector_is_even = true;
            }
            std::cout << "hello" << std::endl; */
            customBinarySearch(deque_main_chain, 0, deque_main_chain.size(), *pair_start_next);
        /* }
        else
        {
            std::cout << "do bin search - 1" << std::endl;
            std::deque<int> tmp(deque_main_chain.begin(), deque_main_chain.end() - 1);
            customBinarySearch( tmp, 0, tmp.size(), *pair_start_next);
        } */
        

        pair_size = steps / 2;
        /* std::find(deque_main_chain.begin(), deque_main_chain.end(), *(vanilla_main_chain_itr + insert_pos)); */
        /* std::cout << "vanilla_main_chain_itr next ==== " << *(vanilla_main_chain_itr + insert_pos) << std::endl; */


        if( pair_size > static_cast<std::size_t>( std::distance( pair_start_next, deque.end() ) ) )
        {
            pair_size = static_cast<std::size_t>( std::distance( pair_start_next, deque.end() ) );
        }
        else if( pair_size > static_cast<std::size_t>( std::distance( pair_start_next, std::find_first_of(pair_start_next, deque.end(), deque_main_chain.begin(), deque_main_chain.end()) ) ) )
        {
            pair_size = static_cast<std::size_t>( std::distance( pair_start_next, std::find_first_of(pair_start_next, deque.end(), deque_main_chain.begin(), deque_main_chain.end()) ) );
        }
        if( std::find(deque_main_chain.begin(), deque_main_chain.end(), *pair_start_next) == deque_main_chain.end() )
        {
            /* deque_main_chain.erase(std::find( deque_main_chain.begin(), deque_main_chain.end(), *pair_start_next) ); */
            /* std::cout << "deque_main_chain = "; */
            /* print_deque(deque_main_chain); */
            /* std::cout << "*pair_start_next = " << *pair_start_next << std::endl;
            std::cout << "insert_pos = " << insert_pos << std::endl; */
            deque_main_chain.insert(deque_main_chain.begin() + insert_pos, *pair_start_next);
        }

        /* std::find(deque.begin(), deque.end(), *(start_deque_main_chain_itr ) ); std::find(deque.begin(), deque.end(), *(start_deque_main_chain_itr ) ); */
        
        /* std::cout << "insert_pos + 1 ====== "  << *(deque_main_chain.begin() + insert_pos + 1) << std::endl;
        std::cout << "pairstart next ====== "  << *pair_start_next << std::endl;
        std::cout << "dis ====== "  << std::distance( pair_start_next, std::find(deque.begin(), deque.end(), *(deque_main_chain.begin() + insert_pos + 1) ) ) << std::endl;
        std::cout << "pair_size ====== "  << pair_size << std::endl; */

        /* if( pair_size > static_cast<std::size_t>( std::distance( pair_start_next, std::find(deque.begin(), deque.end(), *(deque_main_chain.begin() + insert_pos) ) ) ) )
        {
            pair_size = static_cast<std::size_t>( std::distance( pair_start_next, std::find(deque.begin(), deque.end(), *(deque_main_chain.begin() + insert_pos) ) ) );
        } */

        std::deque<int> deque_pair(pair_start_next, pair_start_next + pair_size);
        /* std::cout << "deque_pair ==== ";
        print_deque(deque_pair); */
        pair_start_next = deque.erase(pair_start_next, pair_start_next + pair_size);

        if( deque_main_chain.begin() + insert_pos + 1 == deque_main_chain.end() )
            deque_insert_pos = deque.end();
        else
            deque_insert_pos = std::find(deque.begin(), deque.end(), *(deque_main_chain.begin() + insert_pos + 1));

        /* std::find(deque.begin(), deque.end(), deque_main_chain.begin() + insert_pos + 1); */
        deque.insert( deque_insert_pos, deque_pair.begin(), deque_pair.end() );
     
        vanilla_main_chain_itr++;
        deque_main_chain_itr++;
    }
    /* print_deque(deque);
    std::cout << "================" << std::endl; */
}

void PmergeMe::fordJohnsonDequeSorting( int steps )
{
    /* print_deque( deque );
    std::cout << "++++++++++++++++++++++++++++++++" << std::endl; */
    if(steps >= (int)deque.size())
    {
        for( std::size_t i = 0; i < deque.size(); i += steps )
        {
            deque_main_chain.push_back(deque[i]);
        }
        /* if( vector_is_even == false )
        {
            deque_main_chain.push_back(odd_last_element);
            deque.push_back(odd_last_element);    
        } */
        return ;
    }
    swapPairsIfGreater( steps );
    steps *= 2;
    fordJohnsonDequeSorting( steps );

    insertPairsIntoMainChain( steps );
}


void PmergeMe::print_deque( const std::deque<int> &v )
{
    for( std::deque<int>::const_iterator itr = v.begin(); itr != v.end(); itr++ )
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::customBinarySearch( const std::deque<int> &main_chain, int start, int end, int num ) 
{
    int range = start + ( ( end - start ) / 2 );
    if( main_chain.empty() == true )
        return ;
    if( range >= (int)main_chain.size() )
    {
        insert_pos = (int)main_chain.size();
        return ;
    }
    if (num > main_chain[range]) 
        customBinarySearch(main_chain, range + 1, end, num);
    else if (num < main_chain[range] && start != range)
        customBinarySearch(main_chain, start, range - 1, num);
    else if(num == main_chain[range])
        insert_pos = range;
    else
        insert_pos = range;
}

template<typename T>
T PmergeMe::create_insert_oreder( const T &main_chain )
{
    std::size_t jk_order_prev = 1;
    T vanilla_mainchain;
    T jk_orders(jk_order.begin(), jk_order.end());
    typename T::iterator jk_order_itr = jk_orders.begin();

    vanilla_mainchain.push_back(main_chain[0]);
    jk_order_itr++;
    while ( jk_order_prev < main_chain.size() )
    {
        if(jk_order_prev != 1)
            vanilla_mainchain.insert( vanilla_mainchain.end(), main_chain.rend() - ((jk_order_itr - 1)[0]), main_chain.rend() - ((jk_order_itr - 2)[0]) );
        jk_order_prev = jk_order_itr[0];
        jk_order_itr++;
        if( (jk_order_itr - 1)[0] >= static_cast<int>(main_chain.size()) )
        {
            vanilla_mainchain.insert( vanilla_mainchain.end(), main_chain.rbegin(), main_chain.rend() - ((jk_order_itr - 2)[0]) );
            break;
        }
    }
    return (vanilla_mainchain);
}

std::deque<int> PmergeMe::getDeque() { return (deque); }