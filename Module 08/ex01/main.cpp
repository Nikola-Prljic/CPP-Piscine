#include "Span.hpp"

int main()
{
    /* try
    {
        Span a(1000000);
        a.addNumber(0);
        for(int i = 1; i < 1000000 - 1; i++)
            a.addNumber(i + 5000000);
        std::cout << a.longestSpan() << std::endl;
        std::cout << a.longestSpan() << std::endl;
        std::cout << a.longestSpan() << std::endl;
        a.addNumber(100000022);
        std::cout << a.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } */

    try
    {
        Span a(10);
        a.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Span a(10);
        a.addNumber(2);
        a.addNumber(2);
        a.addNumber(2);
        a.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}