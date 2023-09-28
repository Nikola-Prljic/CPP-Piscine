#include "AForm.hpp"

AForm::AForm( const int need_to_sign, const int need_to_execute, const std::string name, const std::string target ) : _is_signed( false ), _need_to_execute(need_to_execute), _need_to_sign(need_to_sign), _name(name), _target(target)
{
    if ( _need_to_sign < 1 || _need_to_execute < 1 )
        throw AForm::GradeTooHighException();
    if ( _need_to_sign > 150 || _need_to_sign > 150 )
        throw AForm::GradeTooLowException();
    return ;
}

AForm::AForm( AForm &src ) : _is_signed(src._is_signed), _need_to_execute(src.getNeedToExecute()), _need_to_sign(src.getNeedToSign()), _name(src.getName()), _target(src.getTarget())
{
    return ;
}

AForm::~AForm() {}

AForm& AForm::operator=( const AForm &rhs )
{
    if( this != &rhs )
    {
        _is_signed = rhs.getIsSigned();
        _target = rhs.getTarget();
    }
    return *this;
}

void AForm::beSigned( const Bureaucrat &B )
{
    if(_need_to_sign < B.getGrade())
        throw AForm::GradeTooLowException();
    _is_signed = true;
    return ;
}

std::ostream& operator<<( std::ostream& os, const AForm& f)
{
    os << "AForm with Name : " << f.getName() << std::endl <<
          "Is Singed ?    : " << f.getIsSigned() << std::endl <<
          "Need to sing   : " << f.getNeedToSign() << std::endl <<
          "Need to exe    : " << f.getNeedToExecute();
    return os;
}

//get funktions
bool AForm::getIsSigned( void ) const { return _is_signed; }

std::string AForm::getName( void ) const { return _name; }

std::string AForm::getTarget( void ) const { return _target; }

int AForm::getNeedToSign( void ) const { return _need_to_sign; }

int AForm::getNeedToExecute( void ) const { return _need_to_execute; }

void AForm::setIsSigned( bool is_signed )
{
    std::swap(_is_signed, is_signed);
    return;
}

void AForm::setTarget( std::string target )
{
    std::swap(_target, target);
    return;
}
