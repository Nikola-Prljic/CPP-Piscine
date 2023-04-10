#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
    Animal::setType( "Cat" );
    std::cout << "  -> Cat constructor called." << std::endl;
    return ;
}

Cat::~Cat()
{
    std::cout << "  -> Cat destructor called." << std::endl;
    return ;
}