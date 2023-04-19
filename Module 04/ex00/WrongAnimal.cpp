#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("empty")
{
    std::cout << " -> " << type << " WrongAnimal constructor called." << std::endl;
    return ;
}

WrongAnimal::WrongAnimal( std::string _type ) : type(_type)
{
    std::cout << " -> " << _type << " WrongAnimal constructor called." << std::endl;
    return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy )
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
    return ;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << " -> WrongAnimal destructor called." << std::endl;
    return ;
}

std::string WrongAnimal::getType( void ) const
{
    return type;
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal class! no animal, no sound!" << std::endl;
    return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& dc)
{
    std::cout << "Wrong Animal assignment operator called" << std::endl;
    if ( this != &dc )
        this->type = dc.type;
    return *this;
}