#include "ClapTrap.hpp"

int main ( void )
{
    std::string target;

    target = "Fio";
    ClapTrap trap("RipKey");
    trap.attack(target);
    trap.takeDamage(3);
    trap.beRepaired(2);
    trap.takeDamage(10);
    trap.attack(target);
    trap.beRepaired(2);
    return (0);
}