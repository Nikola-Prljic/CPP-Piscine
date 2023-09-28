# include "Intern.hpp"

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
void create_intern_giveBureaucrat( std::string form_name, std::string target )
{
    std::cout << std::endl;
    Intern RandIntern;
    AForm *form;
    Bureaucrat niki("niki", 1);

    form = RandIntern.makeForm(form_name, target);
    if(!form)
        return ;
    niki.signForm(*form);
    niki.executeForm(*form);
    delete (form);
}

int main()
{
    test_create_grade_ToHighBureaucrat();
    /* try{
        Bureaucrat niki("niki", 145 );
        // AForm ff(); should not work! AForm is abstract class.
        ShrubberyCreationForm a1("Franz");
        RobotomyRequestForm b1("Marie");
        PresidentialPardonForm c1("Beni");
        //ShrubberyCreationForm a2(a1);
        niki.signForm(a1);
        niki.signForm(b1);
        niki.signForm(c1);
        //niki.decrement();
        niki.executeForm(a1);
        niki.executeForm(b1);
        niki.executeForm(c1);
        std::cout << a1 << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    } */


    try{
        Bureaucrat a("Niki", 150);
        Bureaucrat a2("Hos", 140);
        a = a2;
        std::cout << a << std::endl;
        std::cout << a2 << std::endl;

        RobotomyRequestForm hi1("lol");
        RobotomyRequestForm hi2("lmfao");
        RobotomyRequestForm hi3(hi1);

        std::cout << "----------------------------------------" << std::endl << hi1 << std::endl;
        a.signForm(hi2);
        hi1 = hi2;
        std::cout << hi1 << std::endl;
        std::cout << hi3 << std::endl << "----------------------------------------" << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    try{
        create_intern_giveBureaucrat( "robotomy request", "Lenox" );
        create_intern_giveBureaucrat( "presidential pardon", "Shani" );
        create_intern_giveBureaucrat( "shrubbery creation", "420 no scope" );
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}