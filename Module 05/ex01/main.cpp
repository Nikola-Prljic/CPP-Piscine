#include "Bureaucrat.hpp"
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
        Form a38(151, "a38");
        std::cout << a38.getName() << std::endl;
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