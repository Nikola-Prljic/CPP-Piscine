#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
    return ;
}

Cure::~Cure()
{
    return ;
}

AMateria* Cure::clone( void ) const
{
    return (new Cure(*this));
}
