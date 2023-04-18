#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _src_inventory()
{
    for(int i = 0; i < 4; i++)
        _src_inventory[i] = NULL;
    return ;
}

MateriaSource::MateriaSource( MateriaSource const &src )
{
    *this = src;
    return ;
}

MateriaSource::~MateriaSource( void )
{
    return ;
}

void MateriaSource::learnMateria( AMateria* src )
{
    for(int i = 0; i < 4; i++)
        if(_src_inventory[i] == NULL)
            _src_inventory[i] = src;
    return ;
}

AMateria* MateriaSource::createMateria( std::string const & type )
{
    if( type.compare("ice") == 0)
    {
        AMateria* ice = new Ice();
        return ice;
    }
    return NULL;
}

MateriaSource& MateriaSource::operator=( MateriaSource const & src)
{
    if(this == &src)
        return *this;
    for(int i = 0; i < 4; i++)
        _src_inventory[i] = src._src_inventory[i];
    return *this;
}