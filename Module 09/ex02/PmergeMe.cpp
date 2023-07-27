#include "PmergeMe.hpp"

PmergeMe::PmergeMe( vectorInt input ) : _vector(input) {}

PmergeMe::~PmergeMe() {}

void PmergeMe::printVector()
{
    for( vectorInt::iterator itr = _vector.begin(); itr != _vector.end(); itr++ )
        std::cout << itr[0] << std::endl;
}