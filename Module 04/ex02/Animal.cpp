#include "Animal.hpp"

Animal::Animal( void ) : type("empty")
{
    std::cout << " -> " << type << " Animal constructor called." << std::endl;
    return ;
}

Animal::Animal( std::string _type ) : type(_type)
{
    std::cout << " -> " << _type << " Animal constructor called." << std::endl;
    return ;
}

Animal::Animal( const Animal& copy )
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal::~Animal()
{
    std::cout << " -> Animal destructor called." << std::endl;
    return ;
}

std::string Animal::getType( void ) const
{
    return type;
}

Animal& Animal::operator=(const Animal& dc)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if ( this != &dc )
        this->type = dc.type;
    return *this;
}
