#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try{
        Bureaucrat niki("niki", 150, 150);
        // AForm ff(); should not work! AForm is abstract class.
        ShrubberyCreationForm a1("a1");
        ShrubberyCreationForm a2(a1);
        //niki.signForm(acf);
        //acf.execute(niki);
        niki.executeForm(a1);
        std::cout << a1 << std::endl;
        //niki.decrement();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}