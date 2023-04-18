#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"

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