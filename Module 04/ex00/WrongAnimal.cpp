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

WrongAnimal::~WrongAnimal()
{
    std::cout << " -> WrongAnimal destructor called." << std::endl;
    return ;
}

void WrongAnimal::setType( const std::string _type)
{
    type = _type;
    return ;
}

std::string WrongAnimal::getType( void ) const
{
    return type;
}

void WrongAnimal::makeSound( void ) const
{
    if (!type.compare("WrongCat"))
        std::cout << "Wrong Miau! Wrong Miau!" << std::endl;
    return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& dc)
{
    std::cout << "Wrong Animal assignment operator called" << std::endl;
    if ( this != &dc )
        this->type = dc.type;
    return *this;
}