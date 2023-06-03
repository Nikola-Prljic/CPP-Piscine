#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm(72, 45, "RobotomyRequestForm", target)
{
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

void RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
    isExecutable( executor );
    if( getIsSigned() == false )
        throw AForm::NotSigned();
    robotomized( getTarget() );
    return ;
}