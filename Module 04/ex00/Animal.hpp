#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    private:
        std::string type;
    
    public:
        Animal( void );
        ~Animal();

        void setType( std::string _type);
        std::string getType( void ) const;
        void makeSound( void ) const;
};

#endif