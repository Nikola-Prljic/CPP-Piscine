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
        virtual ~Animal();

        Animal( const Animal& copy );
        std::string getType( void ) const;
        Animal& operator=(const Animal& dc);
        virtual void makeSound( void ) const = 0;
};

#endif