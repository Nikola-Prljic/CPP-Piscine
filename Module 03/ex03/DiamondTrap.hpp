#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{

private:

    std::string _name;
    DiamondTrap( void );

public:

    DiamondTrap( std::string name );
    DiamondTrap( DiamondTrap& diamond);
    ~DiamondTrap();

    void        whoAmI( void );
    using       ScavTrap::attack;
    DiamondTrap& operator=( DiamondTrap &diamond);

};

#endif