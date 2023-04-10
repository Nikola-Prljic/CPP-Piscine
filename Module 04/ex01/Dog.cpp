#include "Dog.hpp"

Dog::Dog( void ) : _brain(new Brain())
{
    /* this->_brain = new Brain(); */
    Animal::setType( "Dog" );
    std::cout << "   -> Dog constructor called." << std::endl;
    return ;
}

Dog::~Dog()
{
    std::cout << "   -> Dog destructor called." << std::endl;
    delete _brain;
    return ;
}
