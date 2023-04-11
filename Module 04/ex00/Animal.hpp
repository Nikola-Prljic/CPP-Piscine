#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    
    public:
        Animal( void );
        Animal( std::string _type );
        Animal( const Animal& copy );
        virtual ~Animal();

        std::string getType( void ) const;
        void makeSound( void ) const;
        Animal& operator=(const Animal& dc);
};

#endif