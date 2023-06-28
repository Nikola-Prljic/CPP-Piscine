#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
private:
    unsigned int _N;
    std::vector<int> _span;
    std::vector<int> _sorted;
    bool is_sorted;

    Span();
    void sort_span();

public:
    Span( unsigned int N );
    Span( const Span &src );
    ~Span();

    Span &operator=( const Span & rhs );
    void addNumber( int num );
    int longestSpan();
    int shortestSpan();

    std::vector<int> getSpan();
};

std::ostream &operator<<( std::ostream& os, Span &src);

#endif