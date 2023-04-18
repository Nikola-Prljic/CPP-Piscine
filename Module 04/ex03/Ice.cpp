#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
    return ;
}

Ice::~Ice()
{
    return ;
}

AMateria* Ice::clone( void ) const
{
    return (new Ice(*this));
}
