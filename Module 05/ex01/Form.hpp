#ifndef FORM_HPP
# define FORM_HPP

# include "iostream"
# include "Bureaucrat.hpp"

//class Bureaucrat;

class Form
{
private:
    bool _is_signed;
    const std::string _name;
    const int _required_to_sign;
    const int _required_to_execute;
    Form();

public:
    Form( const int required_grade, const std::string name );
    Form( const int required_grade, const int required_to_execute, const std::string name );
    Form( Form &src );
    ~Form();

    Form& operator=( const Form &rhs);
    bool Form::getIsSigned( void ) const;
    std::string Form::getName( void ) const;
    int Form::getRequiredToSing( void ) const;
    int Form::getRequiredToExecute( void ) const;

    void beSigned( const Bureaucrat &B );

};

#endif