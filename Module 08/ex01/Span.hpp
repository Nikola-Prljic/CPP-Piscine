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
    Span( const unsigned int &N );
    Span( const Span &src );
    ~Span();

    Span &operator=( const Span & rhs );
    void addNumber( const int &num );
    int longestSpan();
    int shortestSpan();

    std::vector<int> getSpan() const;
};

std::ostream &operator<<( std::ostream& os, const Span &src);

#endif