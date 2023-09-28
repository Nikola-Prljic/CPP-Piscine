#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm(72, 45, "RobotomyRequestForm", target)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ) : AForm(src.getNeedToSign(), src.getNeedToExecute(), src.getName(), src.getTarget()) 
{
    AForm::setIsSigned(src.getIsSigned());
    AForm::setTarget(src.getTarget());
    return ; 
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    return ;
}

void robotomized( std::string target)
{
    srand((int)time(0));
    int ran = rand() % 2;

    std::cout << ran << " * Brrrrr Brrrrr Brrrr *" << std::endl;
    if( ran )
        std::cout << target <<  " has been robotomized!" << std::endl;
    else
        std::cout << "robotomy " << target << " failed!" << std::endl;
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    AForm::setIsSigned(rhs.getIsSigned());
    AForm::setTarget(rhs.getTarget());
    return *this;
}

void RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
    if( getIsSigned() == false)
        throw AForm::NotSigned();
    else if( executor.getGrade() > getNeedToExecute())
        throw AForm::ExecuteTooHighException();    
    else
        robotomized( getTarget() );
}
