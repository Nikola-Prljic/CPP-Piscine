#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: puplic public ScavTrap, public FragTrap
{

private:

    DiamondTrap( void );

public:

    DiamondTrap( std::string name );
    ~DiamondTrap();

};

#endif