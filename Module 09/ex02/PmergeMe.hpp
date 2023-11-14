#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <cstdlib>

class PmergeMe
{
private:
    std::vector<int> vector;

public:
    PmergeMe( char **argv );
    int argvToVector( char **argv );
};

#endif