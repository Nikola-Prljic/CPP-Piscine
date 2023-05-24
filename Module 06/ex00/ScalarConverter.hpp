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
        void convert();
        void convert_switch();
        void covert_from_int();
        void covert_from_char();
        void covert_from_float();
        void covert_from_double();

        //get funktions
        int getInt();
        char getChar();
        float getFloat();
        double getDouble();
        e_type getType();
        std::string getInput();

        bool isInt();
        void toInt();
        bool isChar();
        void toChar( int c );
        bool isFloat();
        void toFloat();
        bool isDouble();
        void toDouble();
        
        std::string getErrorMsg( std::string error_type_msg );
};

std::ostream& operator<<(std::ostream& os, ScalarConverter& sc);

#endif