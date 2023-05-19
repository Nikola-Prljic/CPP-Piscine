#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

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
        /* std::string _type; */
        char    _char;
        int     _int;
        float   _float;
        e_type _type;

        ScalarConverter();
    
    public:
        ScalarConverter( std::string input );
        void convert();
        void convert_switch();
        void covert_from_int();
        void covert_from_char();
        void covert_from_float();

        bool isInt();
        void toInt();
        bool isChar();
        void toChar( int c );
        bool isFloat();
        void toFloat();
};

std::ostream& operator<<(std::ostream& os, const ScalarConverter& sc);

#endif