#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    this->_brain = new Brain();
    std::cout << "  -> Cat constructor called." << std::endl;
    return ;
}

Cat::~Cat()
{
    std::cout << "  -> Cat destructor called." << std::endl;
    delete this->_brain;
    return ;
}

Cat::Cat( const Cat& src )
{
    *this = src;
    return ;
}

Cat& Cat::operator=( const Cat& src )
{
    std::cout << " Cat copy called. " << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        this->_brain = new Brain( *src._brain );
    }
    return *this;
}

void Cat::makeSound( void ) const
{
    std::cout << "Miau! Miau!"  << std::endl;
    return ;
}