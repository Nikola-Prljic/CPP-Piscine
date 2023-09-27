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
    if( _grade > f.getNeedToSign() )
    {
        std::cout << _name << " could not sign " << f.getName() << std::endl;
        return ;
    }
    f.beSigned( *this );
    std::cout << _name << " signed " << f.getName() << std::endl;
}

void Bureaucrat::executeForm( AForm const & form ) const 
{
    if(form.getIsSigned() == false)
        std::cout << form.getName() << " is not singed " << std::endl;
    else if( getGrade() > form.getNeedToSign() )
        std::cout << getName() << " can't execute " << form.getName() << " because forms grade is too high"<< std::endl;
    else if( getExecute() > form.getNeedToExecute() )
        std::cout << getName() << " can't execute " << form.getName() << " because forms execute is too high"<< std::endl;
    else
    {
        form.execute( *this );
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& be )
{
    os << be.getName() << " with the grade: " << be.getGrade();
    return os;
}