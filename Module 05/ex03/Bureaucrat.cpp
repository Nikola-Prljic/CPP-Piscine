#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string name , int grade ) : _name(name), _grade(grade)
{
    if( _grade > 150 )
        throw Bureaucrat::GradeTooLowException();
    if( _grade < 1 )
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat( Bureaucrat &src) : _name(src._name), _grade(src._grade) { return ; }

Bureaucrat::~Bureaucrat() { return ; }

Bureaucrat& Bureaucrat::operator=( Bureaucrat &rhs )
{
    if( this != &rhs )
        _grade = rhs.getGrade();
    return *this;
}

int Bureaucrat::getGrade( void ) const { return _grade; }

std::string Bureaucrat::getName( void ) const { return _name; }

void Bureaucrat::decrement( void )
{
    if((_grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}

void Bureaucrat::increment( void )
{
    if((_grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade--;
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
    else if( getGrade() > form.getNeedToExecute() )
        std::cout << getName() << " can't execute " << form.getName() << " because forms grade is too high"<< std::endl;
    else
    {
        form.execute( *this );
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& be )
{
    os << "Bureaucrat : " << be.getName() << std::endl;
    os << "grade      : " << be.getGrade() << std::endl;
    return os;
}