#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "  -> Brain constructor called." << std::endl;
    return ;
}

Brain::~Brain()
{
    std::cout << "  -> Brain destructor called." << std::endl;
    return ;
}

Brain::Brain( const Brain& src)
{
    std::cout << "  -> Brain copy constructor called." << std::endl;
    *this = src;
    return ;
}

Brain& Brain::operator=( const Brain& src)
{
    std::cout << "Brain copy..." << std::endl;
    if ( this == &src )
        return *this;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    return *this;
}