#include "Form.hpp"

int main()
{
    try{
        Bureaucrat niki("niki", 150);
        Form a38(149, "a38");
        std::cout << a38.getName() << std::endl;
        niki.signForm( a38 );
        niki.increment();
        niki.signForm( a38 );
        std::cout << a38 << std::endl;
    }
    catch (Bureaucrat::ToHigh &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::ToLow &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Form::ToLow &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Form::ToHigh &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}