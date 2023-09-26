#ifndef FORM_HPP
# define FORM_HPP

# include "iostream"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    bool _is_signed;
    const std::string _name;
    const int _need_to_sign;
    const int _need_to_execute;
    Form();

public:
    Form( const int need_to_sign, const std::string name );
    Form( const int need_to_sign, const int need_to_execute, const std::string name );
    Form( Form &src );
    ~Form();

    Form& operator=( const Form &rhs);
    bool getIsSigned( void ) const;
    std::string getName( void ) const;
    int getNeedToSign( void ) const;
    int getNeedToExecute( void ) const;

    void beSigned( const Bureaucrat &B );

    class ToHigh : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return "Forms grade to high!";}
    };

    class ToLow : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return "Forms grade to low!";}
    };
};

std::ostream& operator<<( std::ostream& os, const Form& fo);

#endif