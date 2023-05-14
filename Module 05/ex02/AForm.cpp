#include "AForm.hpp"

AForm::AForm( const int need_to_sign, const std::string name ) : _is_signed( false ), _need_to_execute(0), _need_to_sign(need_to_sign), _name(name)
{
    if ( _need_to_sign < 1 )
        throw AForm::ToLow();
    if ( _need_to_sign > 150 )
        throw AForm::ToHigh();
    return ;
}

AForm::AForm( const int need_to_sign, const int need_to_execute, const std::string name ) : _is_signed( false ), _need_to_execute(need_to_execute), _need_to_sign(need_to_sign), _name(name)
{
    if ( _need_to_sign < 1 || _need_to_execute < 1 )
        throw AForm::ToLow();
    if ( _need_to_sign > 150 || _need_to_sign > 150 )
        throw AForm::ToHigh();
    return ;
}

AForm::AForm( AForm &src ) : _is_signed(src._is_signed), _need_to_sign(src.getNeedToSign()), _need_to_execute(src.getNeedToExecute()) 
{
    return ;
}

AForm::~AForm() { return ; }

AForm& AForm::operator=( const AForm &rhs )
{
    if( this != &rhs )
        _is_signed = rhs.getIsSigned();
    return *this;
}


void AForm::beSigned( const Bureaucrat &B )
{
    if(_need_to_sign > B.getGrade())
        throw AForm::ToLow();
    if(_need_to_execute > B.getExecute())
        throw AForm::ToLow();
    _is_signed = true;
    return ;
}

void AForm::isExecutable( const Bureaucrat& b ) const
{
    if( _need_to_sign > b.getGrade() )
        throw AForm::ToLow();
    if( _need_to_execute > b.getExecute() )
        throw AForm::ToLow();
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

int AForm::getNeedToSign( void ) const { return _need_to_sign; }

int AForm::getNeedToExecute( void ) const { return _need_to_execute; }