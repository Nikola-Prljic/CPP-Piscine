#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    std::cout << "  -> Cat constructor called." << std::endl;
    return ;
}

Cat::~Cat()
{
    std::cout << "  -> Cat destructor called." << std::endl;
    return ;
}

void Cat::makeSound( void ) const
{
    std::cout << "Miau. Miau." << std::endl;
    return ;
}
