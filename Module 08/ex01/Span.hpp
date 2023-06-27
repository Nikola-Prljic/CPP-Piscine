#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
private:
    unsigned int _N;
    std::vector<int> _value;
    std::vector<int> _sorted;
    bool is_sorted;
    Span();

public:
    Span( unsigned int N );
    ~Span();

    void addNumber( int num );
    int longestSpan();
    int shortestSpan();
};

#endif