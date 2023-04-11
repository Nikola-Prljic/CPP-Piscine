#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog"), _brain(new Brain)
{
    std::cout << "  -> Dog constructor called." << std::endl;
    return ;
}

Dog::~Dog()
{
    std::cout << "  -> Dog destructor called." << std::endl;
    delete this->_brain;
    return ;
}

Dog::Dog( const Dog& src )
{
    *this = src;
    return ;
}

Dog& Dog::operator=( const Dog& src )
{
    std::cout << " Dog copy called. " << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        this->_brain = new Brain( *src._brain );
    }
    return *this;
}