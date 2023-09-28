# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

void test_create_grade_ToHighBureaucrat()
{
    try {
        Bureaucrat nik("nik", 151);
    } 
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
        std::cout << "ko" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
        std::cout << "ok" << std::endl;
    }
    try {
        Bureaucrat nik("nik", 0);
    } 
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
        std::cout << "ok" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
        std::cout << "ko" << std::endl;
    }
    try {
        Bureaucrat nik("nik", 150);
        nik.decrement();
    } 
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
        std::cout << "ko" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
        std::cout << "ok" << std::endl;
    }
    try {
        Bureaucrat nik("nik", 1);
        nik.increment();
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
        std::cout << "ok" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
        std::cout << "ko" << std::endl;
    }
}

int main()
{
    test_create_grade_ToHighBureaucrat();
    try{
        Bureaucrat niki("niki", 150);
        //Bureaucrat niki("niki", 1 );
        // AForm ff(); should not work! AForm is abstract class.
        ShrubberyCreationForm a1("Herbert");
        RobotomyRequestForm b1("Marie");
        PresidentialPardonForm c1("Beni");
        //ShrubberyCreationForm a2(a1);
        std::cout << a1 << std::endl;
        std::cout << b1 << std::endl;
        std::cout << c1 << std::endl;
        niki.signForm(a1);
        niki.signForm(b1);
        niki.signForm(c1);
        //niki.decrement();
        niki.executeForm(a1);
        niki.executeForm(b1);
        niki.executeForm(c1);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}