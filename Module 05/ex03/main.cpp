# include "Intern.hpp"

int main()
{
    /* try{
        Bureaucrat niki("niki", 145, 150);
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
    Intern RandIntern;
    AForm *form;
    Bureaucrat niki("niki", 145, 150);

    form = RandIntern.makeForm("a", "you");
    niki.signForm(*form);
    niki.executeForm(*form);
    delete (form);
    return 0;
}