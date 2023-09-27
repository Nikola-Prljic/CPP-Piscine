#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat nik("nik", 150);
        //nik.decrement();
        std::cout << nik << std::endl;
        nik.increment();
        std::cout << nik << std::endl;
        nik.decrement();
        std::cout << nik << std::endl;
    } 
    catch (Bureaucrat::ToHigh &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::ToLow &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------" << std::endl;
    try {
        Bureaucrat nik("nik", 150);
        Bureaucrat fio("fio", 144);
        Bureaucrat copyOfFio(fio);
        nik = fio;
        std::cout << nik << std::endl;
        std::cout << copyOfFio << std::endl;
    } 
    catch (Bureaucrat::ToHigh &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::ToLow &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}