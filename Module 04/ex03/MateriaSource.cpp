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
    for(int i = 0; i < 4; i++)
        if(_src_inventory[i])
            delete _src_inventory[i];
    return ;
}

void MateriaSource::learnMateria( AMateria* src )
{
    for(int i = 0; i < 4; i++)
    {
        if(_src_inventory[i] == NULL)
        {
            _src_inventory[i] = src;
            return ;
        }
    }
    return ;
}

AMateria* MateriaSource::createMateria( std::string const & type )
{
    AMateria* material;

    if( type.compare("ice") == 0)
        return ( material = new Ice() );
    else if( type.compare("cure") == 0)
        return ( material = new Cure() );
    return material;
}

MateriaSource& MateriaSource::operator=( MateriaSource const & src)
{
    if(this == &src)
        return *this;
    for(int i = 0; i < 4; i++)
        _src_inventory[i] = src._src_inventory[i];
    return *this;
}