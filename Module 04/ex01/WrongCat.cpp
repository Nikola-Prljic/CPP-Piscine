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