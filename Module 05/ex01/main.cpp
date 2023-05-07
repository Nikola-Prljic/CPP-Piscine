#include "Form.hpp"

int main()
{
    /* try 
    {
        Bureaucrat nik("nik", 151);
        std::cout << nik << std::endl;
        nik.increment();
        //nik.decrement();
    } catch (Bureaucrat::ToHigh &e) 
    {
        std::cout << e.what() << std::endl;
    } */

    try
    {
        Bureaucrat niki("niki", 150);
        Form a38(150, "a38");
        std::cout << a38.getName() << std::endl;
        a38.beSigned( niki );
        std::cout << a38 << std::endl;
    }
    catch (Bureaucrat::ToHigh &e) 
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::ToLow &e) 
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::ToLow &e) 
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::ToHigh &e) 
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}