# include "PmergeMe.hpp"
# include <sstream>

PmergeMe::PmergeMe( char **argv ) : vector_is_even(true)
{
    odd_last_element = 42;
    if(argvToVector( argv ))
        return ;

    create_jacob_numbers();
    ford_johnson_vector( 1 );

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

        main_chain.insert( main_chain.begin() + insert_pos, pairs_mainchain_itr[0][pair_start] );
    
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
// -------------------------------------------------------------------------------------------------- //
// -----------------------------/                                \----------------------------------- //
// ----------------------------|    FORD JOHNSON DEQUE SORTING    |---------------------------------- //
// -----------------------------\                                /----------------------------------- //
// -------------------------------------------------------------------------------------------------- //
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

void PmergeMe::swapElementsInRange( deque_itr pair_start, deque_itr pair_end, deque_itr pair_end_next )
{
    bool is_end = false;
    int insert_pos_num = *(pair_end_next + 1);
    std::deque<int> tmp( pair_start, pair_end + 1 );

    if( pair_end_next + 1 == deque.end() )
        is_end = true;
    deque.erase( pair_start, pair_end + 1 );
    if(is_end == false)
        pair_end_next = std::find(deque.begin(), deque.end(), insert_pos_num);
    else
        pair_end_next = deque.end();

    deque.insert( pair_end_next, tmp.begin(), tmp.end() );
}

void PmergeMe::swapPairsIfGreater( int steps )
{
    deque_itr pair_start = deque.begin();
    deque_itr pair_end = pair_start + (steps - 1);
    deque_itr pair_start_next = pair_end + 1;
    deque_itr pair_end_next = pair_start_next + (steps - 1);

    if(steps * 2 > (int)deque.size())
        pair_end_next = deque.end() - 1;
    for( std::size_t i = steps; i < deque.size() && pair_start != deque.end() && pair_start_next != deque.end(); )
    {
        i += steps;
        if( *pair_start < *pair_start_next && (std::size_t)(steps * 2) < deque.size())
        {
            if(steps == 1)
                std::iter_swap(pair_start, pair_start_next);
            else
                swapElementsInRange( pair_start, pair_end, pair_end_next );
        }
        next_step( pair_start, pair_end, pair_start_next, pair_end_next, i, steps );
        i += steps;
        if(i + steps >= deque.size())
            pair_end_next = deque.end() - 1;
    }
}

void PmergeMe::next_step( deque_itr &pair_start, deque_itr &pair_end, deque_itr &pair_start_next, deque_itr &pair_end_next, const int &i, const int &steps )
{
    if( pair_start - deque.begin() + i > (int)deque.size() )
        pair_start = deque.end();
    else
        pair_start = deque.begin() + i;

    if( ( (pair_start - deque.begin()) + (steps - 1) ) > (int)deque.size() )
        pair_end = deque.end();
    else
        pair_end = pair_start + (steps - 1);

    pair_start_next = pair_end + 1;
    pair_end_next = pair_start_next + (steps - 1);
}

std::deque<int> PmergeMe::findElementsToInsert( const int &steps )
{
    std::deque<int> elements_to_insert;
    std::deque<int>::iterator deque_main_chain_itr = deque_main_chain.begin();
    std::deque<int>::iterator deque_next_pair;

    while( deque_main_chain_itr != deque_main_chain.end() )
    {
        std::deque<int>::iterator deque_first_pair = std::find(deque.begin(), deque.end(), *deque_main_chain_itr);
        if( (deque_main_chain_itr + 1) != deque_main_chain.end() )
            deque_next_pair = std::find(deque.begin(), deque.end(), *(deque_main_chain_itr + 1) );
        else
            deque_next_pair = deque.end();
        
        if( *deque_main_chain_itr == *deque_first_pair && std::distance(deque_first_pair, deque_next_pair) > steps / 2)
            elements_to_insert.push_back( *(deque_first_pair + steps / 2));

        deque_main_chain_itr++;
    }
    if(steps == 2 && vector_is_even == false)
    {    
        deque.push_back(odd_last_element);
        elements_to_insert.push_back(odd_last_element);
    }
    return (elements_to_insert);
}

void PmergeMe::insertPairsIntoMainChain( const int &steps, const std::deque<int> &vanilla_main_chain )
{
    std::size_t pair_size = 0;
    std::size_t half_steps = steps / 2; 
    deque_itr pair_start_next = deque.begin() + half_steps;
    std::deque<int>::const_iterator vanilla_main_chain_itr = vanilla_main_chain.begin();

    for( std::size_t i = 0; i < deque.size() && vanilla_main_chain_itr != vanilla_main_chain.end(); i += steps, vanilla_main_chain_itr++ )
    {
        pair_start_next = std::find(deque.begin(), deque.end(), *vanilla_main_chain_itr);
        customBinarySearch(deque_main_chain, 0, deque_main_chain.size(), *pair_start_next);
        pair_size = getPairSize( half_steps, pair_start_next );

        if( std::find(deque_main_chain.begin(), deque_main_chain.end(), *pair_start_next) == deque_main_chain.end() )
            deque_main_chain.insert(deque_main_chain.begin() + insert_pos, *pair_start_next);

        std::deque<int> deque_pair(pair_start_next, pair_start_next + pair_size);

        pair_start_next = deque.erase(pair_start_next, pair_start_next + pair_size);

        deque.insert( findInsertPos(), deque_pair.begin(), deque_pair.end() );
    }
}

std::deque<int>::iterator PmergeMe::findInsertPos()
{
    if( deque_main_chain.begin() + insert_pos + 1 == deque_main_chain.end() )
        return ( deque.end() );
    else
        return ( std::find(deque.begin(), deque.end(), *(deque_main_chain.begin() + insert_pos + 1) ) );
}

//find outs if current pair size is smaller than overall pair size.
std::size_t PmergeMe::getPairSize( const std::size_t &half_steps, std::deque<int>::iterator pair_start_next )
{
    std::size_t distance_to_next_main_chain = static_cast<std::size_t>( std::distance( pair_start_next, deque.end() ) );
    if( half_steps > distance_to_next_main_chain )
        return ( distance_to_next_main_chain );
    
    distance_to_next_main_chain = static_cast<std::size_t>
    (std::distance( pair_start_next,
                    std::find_first_of ( 
                        pair_start_next, deque.end(),
                        deque_main_chain.begin(), deque_main_chain.end()
                    ) ) );

    if( half_steps > distance_to_next_main_chain )
        return ( distance_to_next_main_chain );

    return half_steps;
}

void PmergeMe::fordJohnsonDequeSorting( int steps )
{
    if(steps >= (int)deque.size())
    {
        for( std::size_t i = 0; i < deque.size(); i += steps )
            deque_main_chain.push_back(deque[i]);
        return ;
    }
    swapPairsIfGreater( steps );
    steps *= 2;
    fordJohnsonDequeSorting( steps );

    std::deque<int> vanilla_main_chain( findElementsToInsert( steps ) );

    vanilla_main_chain = create_insert_oreder( vanilla_main_chain );
    insertPairsIntoMainChain( steps, vanilla_main_chain );
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