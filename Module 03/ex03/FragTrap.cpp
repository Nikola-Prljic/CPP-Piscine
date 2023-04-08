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

void FragTrap::highFivesGuys(void)
{
    std::cout << "positive high five" << std::endl;
    return ;
}