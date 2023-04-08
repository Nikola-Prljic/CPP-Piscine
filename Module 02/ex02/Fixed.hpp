#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:

        int num;
        static const int fractional_bits = 8;

    public:

        Fixed( void );
        Fixed( const Fixed &fix );
        Fixed( const int const_int_num );
        Fixed( const float const_float_num);
        Fixed&  operator=( const Fixed &fix );

        //--------- comparison operators ---------//
        bool    operator>( const Fixed &fix ) const;
        bool    operator<( const Fixed &fix ) const;
        bool    operator>=( const Fixed &fix ) const;
        bool    operator<=( const Fixed &fix ) const;
        bool    operator!=( const Fixed &fix ) const;
        bool    operator==( const Fixed &fix ) const;

        //--------- Arithmetic operators ---------//
        Fixed   operator+( const Fixed &fix ) const;
        Fixed   operator-( const Fixed &fix ) const;
        Fixed   operator*( const Fixed &fix ) const;
        Fixed   operator/( const Fixed &fix ) const;

        //---------      ++      --      ---------//
        Fixed   operator++( int );
        Fixed&  operator++( void );
        Fixed   operator--( int );
        Fixed&  operator--( void );

        ~Fixed();

        //get set int float
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        int toInt( void ) const;
        float toFloat( void ) const;

        //min max
        static Fixed& min( Fixed &num1, Fixed &num2 );
        static const Fixed& min( const Fixed &num1, const Fixed  &num2 );
        static Fixed& max( Fixed  &num1, Fixed  &num2 );
        static const Fixed& max( const Fixed  &num1, const Fixed  &num2 );

};

std::ostream& operator<<(std::ostream &out, const Fixed &fix);

#endif