#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string name , int grade, int execute) : _name(name), _grade(grade), _execute(execute)
{
    if( _grade > 150 || _execute > 150)
        throw Bureaucrat::ToLow();
    if( _grade < 1 || _execute < 1)
        throw Bureaucrat::ToHigh();
    return ;
}

Bureaucrat::Bureaucrat( Bureaucrat &src) : _name(src._name), _grade(src._grade), _execute(src._execute) { return ; }

Bureaucrat::~Bureaucrat() { return ; }

Bureaucrat& Bureaucrat::operator=( Bureaucrat &rhs )
{
    if( this != &rhs )
    {
        _grade = rhs.getGrade();
        _execute = rhs.getExecute();
    }
    return *this;
}

int Bureaucrat::getGrade( void ) const { return _grade; }

int Bureaucrat::getExecute( void ) const { return _execute; }

std::string Bureaucrat::getName( void ) const { return _name; }

void Bureaucrat::decrement( void )
{
    if((_grade + 1) > 150)
        throw Bureaucrat::ToLow();
    else
        _grade++;
    return ;
}

void Bureaucrat::increment( void )
{
    if((_grade - 1) < 1)
        throw Bureaucrat::ToHigh();
    else
        _grade--;
    return ;
}

void Bureaucrat::signForm( AForm& f ) const 
{
    try {
        f.beSigned( *this );
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch (AForm::GradeTooLowException &e) {
        std::cout << _name << " coulnd't sign " << f.getName() << " because " << e.what() << std::endl;
    }
    catch (AForm::GradeTooHighException &e) {
        std::cout << _name << " coulnd't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm( AForm const & form ) const
{
    form.isExecutable( *this );
    form.execute( *this );
    std::cout << _name << " executed " << form.getName() << std::endl;
    return ;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& be )
{
    os << be.getName() << " with the grade: " << be.getGrade();
    return os;
}