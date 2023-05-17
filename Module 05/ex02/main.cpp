#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try{
        Bureaucrat niki("niki", 145, 150);
        // AForm ff(); should not work! AForm is abstract class.
        ShrubberyCreationForm a1("a1");
        //ShrubberyCreationForm a2(a1);
        niki.signForm(a1);
        niki.decrement();
        a1.execute(niki);
        //niki.executeForm(a1);
        std::cout << a1 << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}