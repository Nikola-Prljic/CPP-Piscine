#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    int _grade;
    int _execute;
    const std::string _name;
    Bureaucrat();

public:
    Bureaucrat( std::string name, int grade, int execute);
    Bureaucrat( Bureaucrat &src );
    ~Bureaucrat();

    Bureaucrat& operator=( Bureaucrat &rhs );
    int getGrade( void ) const;
    int getExecute( void ) const;
    std::string getName( void ) const;

    void increment( void );
    void decrement( void );

    void signForm( AForm &f ) const;
    void executeForm( AForm const & form ) const;

    class ToHigh : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return "Error: to high!";}
    };

    class ToLow : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return "Error: to low!";}
    };
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& be );

#endif