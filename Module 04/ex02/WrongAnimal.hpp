#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal( void );
        WrongAnimal( std::string _type );
        ~WrongAnimal();

        void setType( std::string _type);
        std::string getType( void ) const;
        void makeSound( void ) const;
        WrongAnimal& operator=(const WrongAnimal& dc);

};

#endif