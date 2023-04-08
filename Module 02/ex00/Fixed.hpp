#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:

    int num;
    static const int  fractional_bits = 8;

public:

    Fixed( void );
    Fixed( const Fixed &fix );
    Fixed& operator=( const Fixed &fix );
    ~Fixed( void );

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif