#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    ScavTrap::hp = 100;
    FragTrap::ep = 50;
    ScavTrap::ad = 30;
    std::cout << "DiamondTrap constructor called." << std::endl;
    return ;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called." << std::endl;
    return ;
}