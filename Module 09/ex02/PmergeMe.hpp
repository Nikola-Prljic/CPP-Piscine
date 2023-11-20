#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
//# include <cstdlib>
//# include <cctype>
# include <algorithm> 

class PmergeMe
{
private:
    int insert_pos;
    std::vector<int> vector;
    std::vector< std::vector<int> > vv;

public:
    PmergeMe( char **argv );

    void ford_johnson_vector( std::vector< std::vector<int> > &v_v, int pair_size );
    void join_pairs_together( std::vector< std::vector<int> > &pairs );

    void binary_search( std::vector<int> main_chain, int start, int end, int num);

    //input to vector and test is num
    bool ft_isnum(char *str);
    int argvToVector( char **argv );

    void print_vector( const std::vector<int> &v );
    void print_vv( const std::vector< std::vector<int> > &v );
};

#endif