#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Character.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _src_inventory[4];

public:
    MateriaSource();
    MateriaSource( MateriaSource const &src );
    ~MateriaSource();
    void learnMateria( AMateria* src );
    AMateria* createMateria( std::string const & type );
    MateriaSource& operator=( MateriaSource const &);

};


#endif