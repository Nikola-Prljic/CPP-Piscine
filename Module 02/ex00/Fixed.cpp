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

Fixed& Fixed::operator=( const Fixed &fix)
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
    std::cout << "getRawBits member function called" << std::endl;
    return (num);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    num = raw;
    return ;
}