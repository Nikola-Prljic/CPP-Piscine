#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string _name ) :name(_name)
{
    this->hp = 10;
    this->ep = 10;
    this->ad = 0;

    std::cout << "Default constructor called" << std::endl;
    return ;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "Destructor called" << std::endl;
    return ;
}


void ClapTrap::attack( const std::string& target )
{
    remove_ep();
    if( is_dead() )
        return ;
    std::cout << "-> ClapTrap " << name << " attacks " << target;
    std::cout << " causing " << this->ad << " points of damage! " << std::endl;
    return ;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    this->hp -= amount;
    if(this->hp < 0)
        this->hp = 0;
    std::cout << "-> ClapTrap " << name << " takes ";
    std::cout << amount << " points of damage and remains with " << this->hp << " hit points." << std::endl;
    return ;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    remove_ep();
    if( is_dead() )
        return ;
    this->hp += amount;
    std::cout << "-> ClapTrap " << name << " repaiers " << amount;
    std::cout << " points and has now " << this->hp << " hit points." << std::endl;
    return ;
}

bool ClapTrap::is_dead( void )
{
    if( this->hp < 1 )
    {
        std::cout << "-> ClapTrap " << name << " is dead!" << std::endl;
        return (IS_ALIVE);
    }
    if( this->ep < 1 )
    {
        std::cout << "-> ClapTrap " << name << " has no energy!" << std::endl;
        return (IS_ALIVE);
    }
    return ( IS_DEAD );
}

void ClapTrap::remove_ep( void )
{
    this->ep -= 1;
    if( this->ep < 0 )
        this->ep = 0;
    return ;
}