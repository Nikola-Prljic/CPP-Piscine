#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try{
        Bureaucrat niki("niki", -151, 1);
        // AForm ff(); should not work! AForm is abstract class.
        ShrubberyCreationForm acf("yoou");
        niki.signForm(acf);
        acf.execute(niki);
        std::cout << acf << std::endl;
        //niki.decrement();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}