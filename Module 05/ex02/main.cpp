#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat niki("niki", 150);
        Bureaucrat niki2("niki2", 150);
        // AForm ff(); should not work! AForm is abstract class.
        ShrubberyCreationForm acf(niki);
        ShrubberyCreationForm acf2(niki2);
        acf = acf2;
        std::cout << acf << std::endl;
        //niki.decrement();
    }
    catch (Bureaucrat::ToHigh &e) 
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::ToLow &e) 
    {
        std::cout << e.what() << std::endl;
    }
    catch (AForm::ToLow &e) 
    {
        std::cout << e.what() << std::endl;
    }
    catch (AForm::ToHigh &e) 
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}