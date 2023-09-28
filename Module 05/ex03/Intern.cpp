#include "Intern.hpp"

Intern::Intern() { return ; }

Intern::Intern( Intern &rhs ) { *this = rhs; }

Intern &Intern::operator=( const Intern &src ) 
{
    *this = src;
    return *this;
}

Intern::~Intern() { return ; }

Options Intern::ChoseOne( std::string form )
{
    if("robotomy request" == form)
        return RRForm;
    if("shrubbery creation" == form)
        return SCForm;
    if("presidential pardon" == form)
        return PPForm;  
    return Option_Invalid;
}

AForm *Intern::makeForm( std::string name, std::string target )
{
    switch (ChoseOne( name ))
    {
    case RRForm:
    {
        std::cout << "Intern creates " << name << std::endl;
        return (new RobotomyRequestForm( target ));
    }
    case PPForm:
    {
        std::cout << "Intern creates " << name << std::endl;
        return (new PresidentialPardonForm( target ));
    }
    case SCForm:
    {
        std::cout << "Intern creates " << name << std::endl;
        return (new ShrubberyCreationForm( target ));
    }
    case Option_Invalid:
        throw Intern::InvalidForm();
    default:
        break;
    }
    return nullptr;
}