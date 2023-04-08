#include "ScavTrap.hpp"

int main ( void )
{
    ScavTrap fio( "Fio" );
    ScavTrap fio2( fio );

    fio2.attack( "the enemy" );
    fio.attack( "the air" );
    fio.takeDamage( 10 );
    fio2.takeDamage( 10 );
    fio.beRepaired( 10 );
    fio.gate_keeper();
    return (0);
}