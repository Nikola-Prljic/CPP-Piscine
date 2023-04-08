#include "Fixed.hpp"

int main( void )
{
    Fixed min(12);
    Fixed max(44);


    std::cout << Fixed::min(min, max) << std::endl;
    std::cout << Fixed::max(min, max) << std::endl;

    Fixed const b2( Fixed( 5.05f ) / Fixed( 2 ) );

    std::cout << "5.05f / 2 = " << b2 << std::endl;

    Fixed c(1);

    std::cout << c++ << std::endl;
    std::cout << c << std::endl;
    std::cout << ++c << std::endl;
    std::cout << c << std::endl << std::endl << std::endl;
    
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    return (0);
}