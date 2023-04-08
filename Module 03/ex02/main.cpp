#include "FragTrap.hpp"

int main ( void )
{
    FragTrap fio( "Fio" );
    FragTrap fio2( fio );

    fio2.attack( "the enemy" );
    fio.attack( "the air" );
    fio.takeDamage( 10 );
    fio2.takeDamage( 10 );
    fio.beRepaired( 10 );
    fio.highFivesGuys();
    return (0);
}