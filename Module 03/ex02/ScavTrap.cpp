#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
    this->hp = 100;
    this->ep = 50;
    this->ad = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
    return ;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
    return ;
}

void ScavTrap::attack( const std::string& target )
{
    ep -= 1;
    if ( this->ep < 1 ) 
    {
        ep = 0;
        std::cout << "-> ScavTrap " << this->name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "-> ScavTrap " << this->name << " attacks " << target;
    std::cout << " causing " << this->ad << " points of damage!" << std::endl;
    return ;
}

void ScavTrap::gate_keeper( void )
{
    std::cout << "-> ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
    return ;
}