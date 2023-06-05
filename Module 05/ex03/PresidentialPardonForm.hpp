#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm();

    public:
        PresidentialPardonForm( std::string target);
        PresidentialPardonForm( const PresidentialPardonForm &src);
        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
        void execute( Bureaucrat const & executor ) const;
};

#endif