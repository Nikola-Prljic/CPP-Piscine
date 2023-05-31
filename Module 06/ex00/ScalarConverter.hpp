#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <climits>
#include <float.h>
#include <sstream>

enum e_type {
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERALS
};

class ScalarConverter
{
    private:
        static std::string _input;
        static std::string error_msg[4];
        static e_type _type;

        static char    _char;
        static int     _int;
        static float   _float;
        static double  _double;
        static long double  _ld;

    public:
        ScalarConverter();
        ScalarConverter( ScalarConverter & rhs );

        ScalarConverter& operator=( ScalarConverter src );

        static void convert( std::string input );
        static void covert_from_int();
        static void covert_from_char();
        static void covert_from_float();
        static void covert_from_double();

        static void toChar( int c );
        static void toFloatOrDuble();
        static bool toDouble();
        static bool isInt();
        static bool isChar();
        static bool isFloat();
        static bool isDouble();
        static void isBiggerFloat();
        static std::string isPseudoLiterals();
        static void setPseudoLiterals();

        static int getInt();
        static char getChar();
        static float getFloat();
        static double getDouble();
        static std::string getInput();
        static e_type getType();
        
        static std::string getErrorMsg( std::string error_type_msg );
};

std::ostream& fixed(std::ostream& os);
std::ostream& operator<<(std::ostream& os, ScalarConverter& sc);

#endif