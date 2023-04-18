#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{

public:
    Cure( void );
    ~Cure();

    virtual AMateria* clone( void ) const;
};

#endif