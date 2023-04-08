#include "Fixed.hpp"

Fixed::Fixed( void ) : num()
{
    std::cout << "Default constructor called" << std::endl;
    num = 0;
    return;
}

Fixed::Fixed( const Fixed &fix ) : num()
{
    std::cout << "Copy constructor called" << std::endl;
    num = fix.num;
    return;
}

Fixed::Fixed( const int n ) : num()
{
    std::cout << "Int constructor called" << std::endl;
    num = n << fractional_bits;
    return ;
}

Fixed::Fixed( const float n ) : num()
{
    std::cout << "Float constructor called" << std::endl;
    num = std::roundf( n * ( 1 << fractional_bits ) );
    return ;
}

Fixed& Fixed::operator=( const Fixed &fix )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &fix)
        num = fix.getRawBits();
    return (*this);
}

Fixed::~Fixed( void )
{
    std::cout << "Destructer called!" << std::endl;
    return;
}


int Fixed::getRawBits( void ) const
{
    return (num);
}

void Fixed::setRawBits( int const raw )
{
    num = raw;
    return ;
}

int Fixed::toInt( void ) const
{
    return ( static_cast<int>( num ) / ( 1 << fractional_bits ) );
}

float Fixed::toFloat( void ) const
{
    return ( static_cast<float>( num ) / ( 1 << fractional_bits ) );
}

std::ostream& operator << ( std::ostream &out, const Fixed &fix )
{
    out << fix.toFloat();
    return ( out );
}