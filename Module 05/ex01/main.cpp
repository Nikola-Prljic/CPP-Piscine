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

    Form a38(1, "a38");
    std::cout << a38.getName() << std::endl;
    return 0;
}