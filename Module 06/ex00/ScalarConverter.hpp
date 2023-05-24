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
        std::string _input;
        std::string error_msg[4];
        e_type _type;

        char    _char;
        int     _int;
        float   _float;
        double  _double;

        ScalarConverter();
    
    public:
        ScalarConverter( std::string input );
        ScalarConverter( ScalarConverter & rhs );

        void convert();
        void covert_from_int();
        void covert_from_char();
        void covert_from_float();
        void covert_from_double();

        void toChar( int c );
        void toFloat();
        void toDouble();
        bool isInt();
        bool isChar();
        bool isFloat();
        bool isDouble();

        int getInt();
        char getChar();
        float getFloat();
        double getDouble();
        std::string getInput();
        e_type getType();
        
        std::string getErrorMsg( std::string error_type_msg );
};

std::ostream& operator<<(std::ostream& os, ScalarConverter& sc);

#endif