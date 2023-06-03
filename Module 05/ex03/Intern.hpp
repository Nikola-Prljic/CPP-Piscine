#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <map>

enum Options { Option_Invalid, RRForm, SCForm, PPForm };

class Intern
{
    private:
        Options ChoseOne( std::string form );
    public:
        Intern();
        Intern( Intern &rhs );
        ~Intern();

        Intern &operator=( const Intern &src );
        AForm *makeForm( std::string form, std::string name );
};

#endif