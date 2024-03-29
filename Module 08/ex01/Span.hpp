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

    Span    &operator=( const Span & rhs );
    void    addNumber( const int &num );
    void    addNumber( std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
    int     longestSpan();
    int     shortestSpan();

    std::vector<int> getSpan() const;
    unsigned int getN() const;
};

std::ostream &operator<<( std::ostream& os, const Span &src);

#endif