#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string name , int grade) : _name(name), _grade(grade)
{
    if( _grade > 150 )
        throw Bureaucrat::GradeTooLowException();
    if( _grade < 1 )
        throw Bureaucrat::GradeTooHighException();
    std::cout << "*Bureaucrat constructor called." << std::endl;
    return ;
}

Bureaucrat::Bureaucrat( Bureaucrat &src) : _name(src._name), _grade(src._grade) { return ; }

Bureaucrat::~Bureaucrat()
{
    std::cout << "*Bureaucrat destroctur called." << std::endl;
    return ;
}

Bureaucrat& Bureaucrat::operator=( Bureaucrat &rhs )
{
    if( this != &rhs )
        this->_grade = rhs.getGrade();
    return *this;
}

int Bureaucrat::getGrade( void ) const { return _grade; }

std::string Bureaucrat::getName( void ) const { return _name; }

void Bureaucrat::increment( void )
{
    if((_grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade--;
    return ;
}

void Bureaucrat::decrement( void )
{
    if((_grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
    return ;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& be )
{
    os << be.getName() << " with the grade: " << be.getGrade();
    return os;
}