#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:

        int num;
        static const int fractional_bits = 8;

    public:

        Fixed( void );
        Fixed( const Fixed &fix );
        Fixed( const int const_int_num );
        Fixed( const float const_float_num );
        Fixed& operator=( const Fixed &fix );
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        int toInt( void ) const;
        float toFloat( void ) const;
};
std::ostream& operator<<(std::ostream &out, const Fixed &fix);
#endif