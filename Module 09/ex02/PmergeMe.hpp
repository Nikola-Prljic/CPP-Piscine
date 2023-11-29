#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <algorithm> 
# include <list>

class PmergeMe
{

private:

    bool vector_is_even;
    int odd_last_element;
    int insert_pos;

    std::vector<int> jk_order;
    std::vector< std::vector<int> > pairs;
    std::vector<int> input_original;

    std::list<int> list;
public:

    PmergeMe( char **argv );

    void create_jacob_numbers();

    // ford_johnson_vector
    void ford_johnson_vector( int pair_size );
    void swap_pairs( std::vector< std::vector<int> > &pairs );
    void join_pairs_together();
    void insert_into_main_chain( std::vector<int> vanilla_mainchain, std::vector<int> mainchain, int pair_size);
    std::vector<int> create_insert_oreder( std::vector<int> main_chain );
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

    // ------------- List sorting ------------

    int argvToList( char **argv );
    void print_list( const std::list<int> &v );

    void ford_johnson_list( int steps );
    std::list<int>::iterator make_list_itr( std::list<int> l, int &steps );
    std::list<int>::iterator list_move_up( std::list<int>::iterator itr, int steps );
    std::list<int>::iterator list_move_up( std::list<int> l, int steps );
    void swap_pairs( std::list<int>::iterator &pair_start, std::list<int>::iterator &pair_end );
    void swap_range( std::list<int>::iterator &pair_start, std::list<int>::iterator &next_pair_start );
};

#endif