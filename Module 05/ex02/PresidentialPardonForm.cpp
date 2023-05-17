#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target) : AForm(25, 5, "PresidentialPardonForm", target)
{
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
    isExecutable( executor );
    if( getIsSigned() == false)
        throw AForm::NotSigned();
    std::cout << "Informs " << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    return ;
}

