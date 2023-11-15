#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
//# include <cstdlib>
//# include <cctype>
//# include <algorithm> 

class PmergeMe
{
private:
    std::vector<int> vector;
    std::vector< std::vector<int> > vv;

public:
    PmergeMe( char **argv );

    void ford_johnson_vector( std::vector< std::vector<int> > &v_v, int i );

    //input to vector and test is num
    bool ft_isnum(char *str);
    int argvToVector( char **argv );

    void print_vector( const std::vector<int> &v );
};

#endif