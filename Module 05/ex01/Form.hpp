#ifndef FORM_HPP
# define FORM_HPP

# include "iostream"
# include "Bureaucrat.hpp"

//class Bureaucrat;

class Form
{
private:
    bool _is_signed;
    const std::string _name;
    const int _required_to_sign;
    const int _required_to_execute;
    Form();

public:
    Form( const int required_grade, const std::string name );
    Form( const int required_grade, const int required_to_execute, const std::string name );
    Form( Form &src );
    ~Form();

    Form& operator=( const Form &rhs);
    bool getIsSigned( void ) const;
    std::string getName( void ) const;
    int getRequiredToSing( void ) const;
    int getRequiredToExecute( void ) const;

    void beSigned( const Bureaucrat &B );

    class ToHigh : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return "Error: Form: Grade to high!";}
    };

    class ToLow : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return "Error: Form: Grade to low!";}
    };
};

#endif