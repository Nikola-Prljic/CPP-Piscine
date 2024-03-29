#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream> 

class Bureaucrat
{
private:
    int _grade;
    const std::string _name;
    Bureaucrat();

public:
    Bureaucrat( std::string name, int grade);
    Bureaucrat( Bureaucrat &src );
    ~Bureaucrat();

    Bureaucrat& operator=( Bureaucrat &rhs );
    int getGrade( void ) const;
    std::string getName( void ) const;

    void increment( void );
    void decrement( void );

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
                return "Grade to low!";}
    };
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& be );

#endif