#include "Intern.hpp"

Intern::Intern() { return ; }

Intern::Intern( Intern &rhs ) { *this = rhs; }

Intern &Intern::operator=( const Intern &src ) 
{
    if( this != &src )
        *this = src;
    return *this;
}

Intern::~Intern() { return ; }

AForm *Intern::makeForm( std::string name, std::string target )
{
    switch(name.compare("robotomy request"))
    {
        case 0:
        {
            std::cout << "Intern creates " << name << std::endl;
            return (new RobotomyRequestForm( target ));
        }
        case -1:
            break;
        default:
            break;
    }
    switch(name.compare("presidential pardon"))
    {
        case 0:
        {
            std::cout << "Intern creates " << name << std::endl;
            return (new PresidentialPardonForm( target ));
        }
        case -1:
            break;
        default:
            break;
    }
    switch(name.compare("shrubbery creation"))
    {
        case 0:
        {
            std::cout << "Intern creates " << name << std::endl;
            return (new ShrubberyCreationForm( target ));
        }
        case -1:
            break;
        default:
            break;
    }
    std::cout << "Intern can't create \"" << name << "\""<< std::endl;
    std::cout << "-> try \"robotomy request\", \"presidential pardon\" or \"shrubbery creation\"" << std::endl;
    throw Intern::InvalidForm();
    return NULL;
}