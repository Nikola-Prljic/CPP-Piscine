#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const Bureaucrat &B ) : AForm(72, 45, "RobotomyRequestForm")
{
    B.signForm( *this );
    if(AForm::getIsSigned() == 0)
        return ;
    return ;
}