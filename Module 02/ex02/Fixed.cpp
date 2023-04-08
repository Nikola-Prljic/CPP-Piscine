#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : num()
{
    num = 0;
    return;
}

Fixed::Fixed( Fixed const &fix ) : num()
{
    num = fix.num;
    return;
}

Fixed::Fixed( const int n ) : num()
{
    num = n << fractional_bits;
    return ;
}

Fixed::Fixed( const float n ) : num()
{
    num = std::roundf( n * ( 1 << fractional_bits ) );
    return ;
}

Fixed& Fixed::operator=( const Fixed &fix )
{
    if(this != &fix)
        num = fix.getRawBits();
    return (*this);
}

Fixed::~Fixed( void )
{
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

std::ostream& operator<<(std::ostream &out, const Fixed &fix)
{
    out << fix.toFloat();
    return ( out );
}

//--------------   min   &&   max   --------------//

Fixed& Fixed::min( Fixed &num1, Fixed &num2 )
{
    if(num2.num < num1.num)
        return (num2);
    return (num1);
}

const Fixed& Fixed::min( const Fixed &num1, const Fixed &num2 )
{
    if(num2.num < num1.num)
        return (num2);
    return (num1);
}

Fixed& Fixed::max( Fixed &num1, Fixed &num2 )
{
    if(num2.num > num1.num)
        return (num2);
    return (num1);
}

const Fixed& Fixed::max( const Fixed &num1, const Fixed &num2 )
{
    if(num2.num > num1.num)
        return (num2);
    return (num1);
}

//-------------- comparison operators --------------//

bool   Fixed::operator>( const Fixed &fix ) const
{
    return ( this->getRawBits() > fix.getRawBits() );
}

bool   Fixed::operator<( const Fixed &fix ) const
{
    return ( this->getRawBits() < fix.getRawBits() );
}

bool   Fixed::operator>=( const Fixed &fix ) const
{
    return ( this->getRawBits() >= fix.getRawBits() );
}

bool   Fixed::operator<=( const Fixed &fix ) const
{
    return ( this->getRawBits() <= fix.getRawBits() );
}

bool   Fixed::operator!=( const Fixed &fix ) const
{
    return ( this->getRawBits() == fix.getRawBits() );
}

bool   Fixed::operator==( const Fixed &fix ) const
{
    return ( this->getRawBits() != fix.getRawBits() );
}

//-------------- Arithmetic operators --------------//

Fixed   Fixed::operator+( const Fixed &fix ) const 
{
    return this->toFloat() + fix.toFloat();
}

Fixed   Fixed::operator-( const Fixed &fix ) const 
{
    return this->toFloat() - fix.toFloat();
}

Fixed   Fixed::operator*( const Fixed &fix ) const 
{
    return this->toFloat() * fix.toFloat();
}

Fixed   Fixed::operator/( const Fixed &fix ) const 
{
    if(fix.toFloat() == 0)
    {
        std::cout << "Error: No Division by Zero you clown :P" << std::endl;
        return *this;
    }
    return this->toFloat() / fix.toFloat();
}

//---------      ++      --      ---------//

Fixed   Fixed::operator++( int )
{
    Fixed tmp = *this;
    num++;
    return tmp;
}

Fixed&   Fixed::operator++( void )
{
    num++;
    return *this;
}

Fixed   Fixed::operator--( int )
{
    Fixed tmp = *this;
    num--;
    return tmp;
}

Fixed&   Fixed::operator--( void )
{
    num--;
    return *this;
}