#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
    private:

        std::string type;
    
    public:

        Animal( void );
        virtual ~Animal();

        void setType( std::string _type);
        std::string getType( void ) const;
        void makeSound( void ) const;
};

#endif