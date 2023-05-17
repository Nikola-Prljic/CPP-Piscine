#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try{
        Bureaucrat niki("niki", 145, 150);
        // AForm ff(); should not work! AForm is abstract class.
        ShrubberyCreationForm a1("a1");
        RobotomyRequestForm b1("b1");
        //ShrubberyCreationForm a2(a1);
        niki.signForm(a1);
        niki.signForm(b1);
        //niki.decrement();
        a1.execute(niki);
        b1.execute(niki);
        //niki.executeForm(a1);
        std::cout << a1 << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}