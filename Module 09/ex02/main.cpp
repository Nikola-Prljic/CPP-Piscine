#include "PmergeMe.hpp"

void test_vector( PmergeMe &a )
{
    std::vector<int> input_dup( a.getInput_original() );

    std::sort( input_dup.begin(), input_dup.end() );
    for(std::size_t i = 0; i < a.getPairs().size(); i++ )
        if( input_dup[i] != a.getPairs()[i][0] )
        {
            std::cout << "vector not sorted" << std::endl;
            return ;
        }
    std::cout << "vector is sorted" << std::endl;
}

int main( int argc, char **argv )
{
    if(argc < 2)
        return (1);
    PmergeMe a(argv);
    test_vector( a );
    return (0);
}