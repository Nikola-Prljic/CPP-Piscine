#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    std::cout << "------------------------" << std::endl;

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "------------------------" << std::endl;
    try
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
        std::cout << " -> big span test: ko" << std::endl;
        std::cerr << e.what() << '\n';
    }
    std::cout << " -> big span test: ok" << std::endl;
    std::cout << "------------------------" << std::endl;
    try
    {
        Span a(10);
        a.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << " -> empty span test: ok" << std::endl;
    }
    std::cout << "------------------------" << std::endl;
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
        std::cerr << e.what() << std::endl;
        std::cout << " -> small span test: ko" << std::endl;
    }
    std::cout << " -> small span test: ok" << std::endl;
    std::cout << "------------------------" << std::endl;
    return 0;
}