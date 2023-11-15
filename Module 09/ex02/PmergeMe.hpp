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

public:
    PmergeMe( char **argv );

    //input to vector and test is num
    bool ft_isnum(char *str);
    int argvToVector( char **argv );

    void print_int( int value);
    void print_vector( const std::vector<int> &v );
};

#endif