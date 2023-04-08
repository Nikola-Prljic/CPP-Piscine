#include "Animal.hpp"

Animal::Animal( void ) : type()
{
    type = "empty";
    std::cout << " -> Animal constructor called." << std::endl;
    return ;
}

Animal::~Animal()
{
    std::cout << " -> Animal destructor called." << std::endl;
    return ;
}

void Animal::setType( const std::string _type)
{
    type = _type;
    return ;
}

std::string Animal::getType( void ) const
{
    return type;
}

void Animal::makeSound( void ) const
{
    if(!type.compare("Dog"))
        std::cout << "Wuff! Wuff!" << std::endl;
    else if (!type.compare("Cat"))
        std::cout << "Miau! Miau!" << std::endl;
    return ;
}