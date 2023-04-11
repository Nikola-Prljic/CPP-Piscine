#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
    std::cout << "  -> Dog constructor called." << std::endl;
    return ;
}

Dog::~Dog()
{
    std::cout << "  -> Dog destructor called." << std::endl;
    return ;
}
