#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    Bureaucrat();

public:
    Bureaucrat( std::string name, int grade );
    Bureaucrat( Bureaucrat &src );
    ~Bureaucrat();

    Bureaucrat& operator=( Bureaucrat &rhs );
    int getGrade( void ) const;
    std::string getName( void ) const;

    void increment( void );
    void decrement( void );

    void signForm( AForm &f ) const;
    void executeForm( AForm const & form ) const;

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return "Grade to high!";}
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return "Grade to Low!";}
    };
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& be );

#endif