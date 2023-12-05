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

    bool vector_is_even;
    int odd_last_element;
    int insert_pos;

    std::vector<int> jk_order;
    std::vector< std::vector<int> > pairs;
    std::vector<int> input_original;

    std::deque<int> deque;
    std::deque<int> deque_main_chain;
    typedef std::deque<int>::iterator deque_itr;

public:

    PmergeMe( char **argv );

    void create_jacob_numbers();

    // ford_johnson_vector
    void ford_johnson_vector( int pair_size );
    void swap_pairs( std::vector< std::vector<int> > &pairs );
    void join_pairs_together();
    void insert_into_main_chain( std::vector<int> vanilla_mainchain, std::vector<int> mainchain, int pair_size);
    /* std::vector<int> create_insert_oreder( std::vector<int> main_chain ); */
    void get_pair_size( std::vector< std::vector<int> >::iterator pairs_mainchain_itr, int pair_size, int &pair_start, int &pair_end );
    void binary_search( std::vector<int> main_chain, int start, int end, int num);

    //input to vector and test is num
    bool ft_isnum(char *str);
    int argvToVector( char **argv );

    //print and getter
    void print_vector( const std::vector<int> &v );
    void print_vv( const std::vector< std::vector<int> > &v );
    std::vector< std::vector<int> > getPairs();
    std::vector< int > getInput_original();

    // ------------- deque sorting ------------

    int argvTodeque( char **argv );
    void print_deque( const std::deque<int> &v );

    void ford_johnson_deque( int steps );
    void swap_pairs( int steps );
    void swap_range( deque_itr &pair_start, deque_itr pair_end, deque_itr &next_pair_start );
    void insert_pairs( const int &steps );
    void binary_search( std::deque<int> main_chain, int start, int end, int num );
    template<typename T > T create_insert_oreder( const T &main_chain );
    std::deque<int> make_elements_to_insert( const int &steps );
};

#endif