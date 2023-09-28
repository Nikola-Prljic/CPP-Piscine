#include "Bureaucrat.hpp"

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
    try {
        Bureaucrat nik("nik", 150);
        //nik.decrement();
        std::cout << nik << std::endl;
        nik.increment();
        std::cout << nik << std::endl;
        nik.decrement();
        std::cout << nik << std::endl;
    } 
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------" << std::endl;
    try {
        Bureaucrat nik("nik", 150);
        Bureaucrat fio("fio", 144);
        Bureaucrat copyOfFio(fio);
        nik = fio;
        std::cout << nik << std::endl;
        std::cout << copyOfFio << std::endl;
    } 
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}