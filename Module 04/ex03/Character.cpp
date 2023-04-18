#include "Character.hpp"

Character::Character( std::string name ) : _name(name)
{
    for(int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    return ;
}

Character::~Character()
{
    std::cout << "Character destructor called!" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(this->_inventory[i])
            delete this->_inventory[i];
    }
    return ;
}

Character::Character( Character const &src )
{
    *this = src;
    return ;
}

Character& Character::operator=( Character const &src )
{
    return *this = src;
}

std::string const & Character::getName() const
{
    return _name;
}

int index_test( int idx, AMateria* _inventory, std::string msg)
{
    if(idx < 0 || idx > 3 || _inventory == NULL)
    {
        std::cout << msg << idx << std::endl;
        return (1);
    }
    return (0);
}

void Character::unequip( int idx )
{
    if(index_test(idx, this->_inventory[idx], "Can't unequip "))
        return ;
    delete this->_inventory[idx];
    this->_inventory[idx] = NULL;
    std::cout << "unequip " << idx << std::endl;
    return ;
}

void Character::equip( AMateria* m )
{
    for(int i = 0; i < 4; i++)
    {
        if(this->_inventory[i] == NULL)
        {
            std::cout << "equip " << m->getType() << std::endl;
            this->_inventory[i] = m;
            return ;
        }
    }
    std::cout << "Full!" << std::endl;
    return ;
}

void Character::use( int idx, ICharacter& target )
{
    if(index_test(idx, this->_inventory[idx], "Can't attack this index: "))
        return ;
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return ;
}