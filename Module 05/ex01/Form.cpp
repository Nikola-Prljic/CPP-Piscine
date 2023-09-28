#include "Form.hpp"

Form::Form( const int need_to_sign, const int need_to_execute, const std::string name ) : _is_signed( false ), _need_to_execute(need_to_execute), _need_to_sign(need_to_sign), _name(name)
{
    if ( _need_to_sign < 1 || _need_to_execute < 1 )
        throw Form::GradeTooHighException();
    if ( _need_to_sign > 150 || _need_to_sign > 150 )
        throw Form::GradeTooLowException();
    return ;
}

Form::Form( Form &src ) : _is_signed(src._is_signed), _need_to_execute(src.getNeedToExecute()), _need_to_sign(src.getNeedToSign()) { return ; }

Form::~Form() {};

Form& Form::operator=( const Form &rhs )
{
    if( this != &rhs )
        _is_signed = rhs.getIsSigned();
    return *this;
}

bool Form::getIsSigned( void ) const { return _is_signed; }

std::string Form::getName( void ) const { return _name; }

int Form::getNeedToSign( void ) const { return _need_to_sign; }

int Form::getNeedToExecute( void ) const { return _need_to_execute; }

void Form::beSigned( const Bureaucrat &B )
{
    if(_need_to_sign < B.getGrade())
        throw Form::GradeTooLowException();
    _is_signed = true;
    return ;
}

std::ostream& operator<<( std::ostream& os, const Form& f)
{
    os << "Form with Name : " << f.getName() << std::endl <<
          "Is Singed ?    : " << f.getIsSigned() << std::endl <<
          "Need to sing   : " << f.getNeedToSign() << std::endl <<
          "Need to exe    : " << f.getNeedToExecute();
    return os;
}