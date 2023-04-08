#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    ClapTrap::name = name + "_clap_name";
    ScavTrap::hp = 100;
    FragTrap::ep = 50;
    ScavTrap::ad = 30;

    std::cout << "<> DiamondTrap <> " << this->_name << " constructor called." << std::endl;
    return ;
}

DiamondTrap::DiamondTrap( DiamondTrap& diamond ) : ClapTrap(diamond._name), ScavTrap(diamond._name), FragTrap(diamond._name)
{
    this->_name = diamond._name;
    ClapTrap::operator=(diamond);
    std::cout << "new hp = " << this->hp << ", new ep = " << this->ep << ", new ad = " << this->ad << std::endl;
    std::cout << "<> DiamondTrap <> " << this->_name << " copy constructor called." << std::endl;
    return ;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "<> DiamondTrap <> " << this->_name << " destructor called." << std::endl;
    return ;
}

void    DiamondTrap::whoAmI( void ) 
{
    std::cout << ">Hello. I am a Diamond trap with the name: " << this->_name << std::endl;
    std::cout << ">ClapTrap name: " << ClapTrap::name << std::endl;
    return ;
}

DiamondTrap& DiamondTrap::operator=( DiamondTrap& diamond )
{
    this->_name = diamond._name;
    ClapTrap::operator=(diamond);
    std::cout << "new hp = " << this->hp << ", new ep = " << this->ep << ", new ad = " << this->ad << std::endl;
    return ( *this );
}