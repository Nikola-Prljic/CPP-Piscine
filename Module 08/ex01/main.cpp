#include "Span.hpp"

void big_test()
{
    try {
        std::vector<int>    l( 10000 );
        std::srand( time ( NULL ) );
        std::generate( l.begin(), l.end(), std::rand );

        Span span( l.size() );

        span.addNumber( l.begin(), l.end() );

        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl; 
    }
}

void range_test()
{
    std::vector<int> ls;

    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);

    Span sp(5);
    try
    {
        sp.addNumber(4);
        sp.addNumber(2);
        sp.addNumber(ls.begin() + 1, ls.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << sp << std::endl;
}

int main()
{
    Span sp = Span(5);

    std::cout << "------------------------" << std::endl;

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "sp = " << sp << std::endl;
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

    std::cout << " -> add range: " << std::endl;
    range_test();
    big_test();
    Span sp1 = Span(5);
    sp1.addNumber(6);
    sp1.addNumber(3);
    sp1.addNumber(17);
    sp1.addNumber(9);
    sp1.addNumber(11);
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
    return 0;
}