#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string name , int grade ) : _name(name), _grade(grade)
{
    if( _grade > 150 )
        throw Bureaucrat::ToLow();
    if( _grade < 1 )
        throw Bureaucrat::ToHigh();
    std::cout << "*Bureaucrat constructor called." << std::endl;
    return ;
}

Bureaucrat::Bureaucrat( Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
    return ;
}

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

int Bureaucrat::getGrade( void ) const
{
    return _grade;
}

std::string Bureaucrat::getName( void ) const
{
    return _name;
}

void Bureaucrat::decrement( void )
{
    if((_grade + 1) > 150)
        throw Bureaucrat::ToHigh();
    else
        _grade++;
    return ;
}

void Bureaucrat::increment( void )
{
    if((_grade - 1) < 1)
        throw Bureaucrat::ToLow();
    else
        _grade--;
    return ;
}

void    Bureaucrat::signForm( Form& f ) 
{
    try {
        f.beSigned( *this );
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch (Form::ToLow &e) {
        std::cout << _name << " coulnd't sign " << f.getName() << " because " << e.what() << std::endl;
    }
    catch (Form::ToHigh &e) {
        std::cout << _name << " coulnd't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& be )
{
    os << be.getName() << " with the grade: " << be.getGrade();
    return os;
}