#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("")
{
    std::cout << "AMateria default constructor called" << std::endl;
    return ;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    return ;
}

AMateria::AMateria( const AMateria& copy )
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = copy;
}

AMateria::~AMateria()
{
    std::cout << " -> AMateria destructor called." << std::endl;
    return ;
}

std::string const & AMateria::getType( void ) const
{
    return _type;
}

void AMateria::use( ICharacter& target )
{
    std::cout << "AMateria use " << _type << " on target " << target.getName() << std::endl;
    return ;
}
