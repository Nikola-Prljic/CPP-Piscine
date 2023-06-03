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
    std::map<std::string, Options> mymap;
    std::map<std::string, Options>::iterator it;

    mymap["RobotomyRequestForm"] = RRForm;
    mymap["ShrubberyCreationForm"] = SCForm;
    mymap["PresidentialPardonForm"] = PPForm;

    it = mymap.find( form );
    if( it != mymap.end() )
    {
        std::cout << "-> Intern creates " << it->first << std::endl;
        return it->second;
    }
    return Option_Invalid;
}

AForm *Intern::makeForm( std::string name, std::string target )
{
    switch (ChoseOne( name ))
    {
    case RRForm:
        return (new RobotomyRequestForm( target ));
    case PPForm:
        return (new PresidentialPardonForm( target ));
    case SCForm:
        return (new ShrubberyCreationForm( target ));
    case Option_Invalid:
        std::cout << "Invalid Form" << std::endl; break;
    default:
        break;
    }
    return nullptr;
}