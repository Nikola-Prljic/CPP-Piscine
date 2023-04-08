#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    this->hp = 100;
    this->ep = 100;
    this->ad = 30;
    std::cout << "FragTrap constructor called" << std::endl;
    return ;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
}

void FragTrap::attack( const std::string& target )
{
    ep -= 1;
    if ( this->ep < 1 ) 
    {
        ep = 0;
        std::cout << "-> FragTrap " << this->name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "-> FragTrap " << this->name << " attacks " << target;
    std::cout << " causing " << this->ad << " points of damage!" << std::endl;
    return ;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "positive high five" << std::endl;
    return ;
}