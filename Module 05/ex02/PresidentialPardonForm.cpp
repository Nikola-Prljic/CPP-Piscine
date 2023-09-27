#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target) : AForm(25, 5, "PresidentialPardonForm", target)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) : AForm(src.getNeedToSign(), src.getNeedToExecute(), src.getName(), src.getTarget()) 
{
    AForm::setIsSigned(src.getIsSigned());
    return ; 
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    AForm::setIsSigned(rhs.getIsSigned());
    AForm::setTarget(rhs.getTarget());
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
    if( getIsSigned() == false)
        throw AForm::NotSigned();
    else if( executor.getGrade() > getNeedToSign())
        throw AForm::GradeTooHighException();
    else if( executor.getExecute() > getNeedToExecute())
        throw AForm::ExecuteTooHighException();
    else
        std::cout << "Informs " << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
