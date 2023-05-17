#ifndef RBOTOMYREQUESTFORM_HPP
# define RBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    RobotomyRequestForm();

public:
    RobotomyRequestForm( std::string target );
    ~RobotomyRequestForm();
};



#endif