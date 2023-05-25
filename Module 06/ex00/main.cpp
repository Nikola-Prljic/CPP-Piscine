#include "ScalarConverter.hpp"

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

    // Test overload = 

    /* ScalarConverter b;         
    std::cout << b << std::endl;
    b = a;
    std::cout << b << std::endl; */

    return (0);
}