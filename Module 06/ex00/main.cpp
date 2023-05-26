#include "ScalarConverter.hpp"

int ScalarConverter::is{ 1 };

int ScalarConverter::getIs(){ return is; }

int ScalarConverter::iDoNothing()
{
    is = 3;
    return is;
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Error: Just one arg" << std::endl;
        return (0);
    }
    ScalarConverter a;
    a.convert(argv[1]);
    std::cout << a << std::endl;

    std::cout << a.getIs() << std::endl;
    std::cout << a.iDoNothing() << std::endl;
    std::cout << a.getIs() << std::endl;

    // Test overload = 

    /* ScalarConverter b;         
    std::cout << b << std::endl;
    b = a;
    std::cout << b << std::endl; */

    return (0);
}