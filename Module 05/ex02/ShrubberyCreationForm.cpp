#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( Bureaucrat& target ) : AForm(145, 137, "ShrubberyCreationForm")
{
    target.signForm( *this );
    if(AForm::getIsSigned() == 0)
        return ;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return ;
}

void ShrubberyCreationForm::tmp()
{
    return ;
}