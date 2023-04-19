#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
    std::cout << "  -> WrongCat constructor called." << std::endl;
    return ;
}

WrongCat::~WrongCat()
{
    std::cout << "  -> WrongCat destructor called." << std::endl;
    return ;
}

void WrongCat::makeSound( void ) const
{
    std::cout << "Wrong miau! Wrong miau!" << std::endl;
    return ;
}