#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <algorithm> 
# include <deque>
# include <iterator>

class PmergeMe
{

private:

    double deque_time;
    double vector_time;

    bool vector_is_even;
    int odd_last_element;
    int insert_pos;

    std::vector<int> jk_order;
    std::vector< std::vector<int> > pairs;
    std::vector<int> input_original;

    std::deque<int> deque;
    std::deque<int> deque_main_chain;
    typedef std::deque<int>::iterator deque_itr;

    void create_jacob_numbers();

    // ford_johnson_vector
    void ford_johnson_vector( int pair_size );
    void swapPairsIfGreater( std::vector< std::vector<int> > &pairs );
    void join_pairs_together();
    void insert_into_main_chain( const std::vector<int> &vanilla_mainchain, std::vector<int> &mainchain, int pair_size);
    void get_pair_size( const std::vector< std::vector<int> >::const_iterator &pairs_mainchain_itr, const int &pair_size, int &pair_start, int &pair_end );
    void customBinarySearch( const std::vector<int> &main_chain, int start, int end, int num);

    //input to vector and test is num
    bool ft_isnum(const char *str);
    int argvToVector( char **argv );


    // ------------- deque sorting ------------

    int argvTodeque( char **argv );

    void fordJohnsonDequeSorting( int steps );
    void swapPairsIfGreater( int steps );
    void next_step( deque_itr &pair_start, deque_itr &pair_end, deque_itr &pair_start_next, deque_itr &pair_end_next, const int &i, const int &steps );
    void swapElementsInRange( deque_itr pair_start, deque_itr pair_end, deque_itr next_pair_end );
    void insertPairsIntoMainChain( const int &steps, const std::deque<int> &vanilla_main_chain );
    void customBinarySearch( const std::deque<int> &main_chain, int start, int end, int num );
    template<typename T > T create_insert_oreder( const T &main_chain );
    std::deque<int> findElementsToInsert( const int &steps );
    std::size_t getPairSize( const std::size_t &half_steps, std::deque<int>::iterator pair_start_next );
    std::deque<int>::iterator findInsertPos();


public:

    PmergeMe( char **argv );
    PmergeMe( const PmergeMe &src );

    //print
    void print_vector( const std::vector<int> &v );
    void print_vv( const std::vector< std::vector<int> > &v );
    void print_deque( const std::deque<int> &v );
    void printTimes();

    //geter
    std::vector< std::vector<int> > getPairs();
    std::vector< int > getInput_original();
    std::deque<int> getDeque();
};

#endif