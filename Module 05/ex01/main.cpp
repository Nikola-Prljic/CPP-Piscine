#include "Form.hpp"

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
        niki.increment();
        Form a38(149, 1, "a38");
        std::cout << a38.getName() << std::endl;
        niki.signForm( a38 );
        niki.increment();
        niki.signForm( a38 );
        std::cout << a38 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}