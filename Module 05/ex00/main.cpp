#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat nik("nik", 151);
        std::cout << nik << std::endl;
        nik.increment();
        //nik.decrement();
    } catch (Bureaucrat::ToHigh &e) 
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}