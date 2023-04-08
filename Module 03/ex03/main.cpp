#include "DiamondTrap.hpp"

void putchar_with_len( std::string line, int len)
{
    std::cout << std::endl;
    for(int i = 0; i < len; i++)
        std::cout << line;
    std::cout << std::endl << std::endl;
    return ;
}

int main ( void )
{
    DiamondTrap dia_1( "Fio" );
    dia_1.attack( "Arthas" );
    DiamondTrap dia_2( dia_1 );
    DiamondTrap dia_3( "Rouge" );

    putchar_with_len("####", 13);

    dia_1.attack( "Ragnaros" );
    dia_2.attack( "Ragnaros" );
    dia_3.attack( "Ragnaros" );
    std::cout << std::endl;
    dia_1.whoAmI();
    dia_2.whoAmI();
    dia_3.whoAmI();
    std::cout << std::endl;
    dia_3.takeDamage(77);
    dia_1 = dia_3;
    dia_1.whoAmI();
    std::cout << std::endl;
    dia_1.beRepaired( 8 );
    dia_2.takeDamage( 13 );
    putchar_with_len("####", 13);
    return (0);
}