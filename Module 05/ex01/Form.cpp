#include "Form.hpp"

Form::Form( const int required_to_sign, const std::string name ) : _is_signed( false ), _required_to_execute(0), _required_to_sign(required_to_sign), _name(name)
{
    if ( _required_to_sign < 1 )
        throw Form::ToLow();
    if ( _required_to_sign > 150 )
        throw Form::ToHigh();
    return ;
}

Form::Form( const int required_to_sign, const int required_to_execute, const std::string name ) : _is_signed( false ), _required_to_execute(required_to_execute), _required_to_sign(required_to_sign), _name(name)
{
    if ( _required_to_sign < 1 )
        throw Form::ToLow();
    if ( _required_to_sign > 150 )
        throw Form::ToHigh();
    return ;
}

Form::Form( Form &src ) : _is_signed(src._is_signed), _required_to_sign(src.getRequiredToSing()), _required_to_execute(src.getRequiredToExecute())
{
    return ;
}

Form::~Form() {};

Form& Form::operator=( const Form &rhs )
{
    if( this != &rhs )
        _is_signed = rhs.getIsSigned();
    return *this;
}

bool Form::getIsSigned( void ) const
{
    return _is_signed;
}

std::string Form::getName( void ) const
{
    return _name;
}

int Form::getRequiredToSing( void ) const
{
    return _required_to_sign;
}

int Form::getRequiredToExecute( void ) const
{
    return _required_to_execute;
}

void    Form::beSigned( const Bureaucrat &B )
{
    if(_required_to_sign > B.getGrade())
        throw Form::ToLow();
    _is_signed = true;
    return ;
}

std::ostream& operator<<( std::ostream& os, const Form& f)
{
    os << "Form with Name : " << f.getName() << std::endl <<
          "Is Singed ?    : " << f.getIsSigned() << std::endl <<
          "Need to sing   : " << f.getRequiredToSing() << std::endl <<
          "Need to exe    : " << f.getRequiredToExecute();
    return os;
}