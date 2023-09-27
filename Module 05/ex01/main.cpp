#include "Form.hpp"

int main()
{
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