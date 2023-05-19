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
        e_type _type;

        ScalarConverter();
    
    public:
        ScalarConverter( std::string input );
        void convert();
        void convert_switch();
        void covert_from_int();
        void covert_from_char();

        void toInt();
        void toChar( int c );
        bool isInt();
        bool isChar();
};

#endif