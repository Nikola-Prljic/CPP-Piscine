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


    try{
        Bureaucrat a("Niki", 150, 150);
        Bureaucrat a2("Hos", 140, 140);
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
        Intern RandIntern;
        AForm *form;
        Bureaucrat niki("niki", 145, 150);

        form = RandIntern.makeForm("a", "you");
        if(!form)
            return (1);
        niki.signForm(*form);
        niki.executeForm(*form);
        delete (form);
    }
        catch(const std::exception& e){
            std::cerr << e.what() << std::endl;
    }
    return 0;
}