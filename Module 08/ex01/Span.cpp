#include "Span.hpp"

Span::Span() {}

Span::Span( unsigned int N ) : _N(N), _span(), _sorted(), is_sorted(false) {}

Span::Span( const Span &src ) : _N(src._N), _span(src._span), _sorted(src._sorted), is_sorted(src.is_sorted) {}

Span::~Span() {}

Span &Span::operator=( const Span & rhs )
{
    _N = rhs._N;
    _span = rhs._span;
    _sorted = rhs._sorted;
    is_sorted = rhs.is_sorted;
    return *this;
}

void Span::addNumber( int num )
{
    if(_span.size() >= _N)
        throw std::out_of_range("Span: Full, can't add more");
    _span.push_back(num);
    is_sorted = false;
}

void Span::sort_span()
{
    if(_span.empty() == true || _span.size() == 1)
        throw std::logic_error("Span: stack to small");
    if(is_sorted == false)
    {
        _sorted = _span;
        std::sort(_sorted.begin(), _sorted.end());
        is_sorted = true;
    }
}

int Span::longestSpan()
{
    sort_span();
    return _sorted.back() - _sorted.front();
}

int Span::shortestSpan()
{
    sort_span();
    return _sorted[1] - _sorted.front();
}

std::vector<int> Span::getSpan() const { return _span; }

std::ostream &operator<<( std::ostream& os, const Span &src)
{
    std::vector<int> tmp = src.getSpan();
    for(std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
        os << it[0] << " ";
    return os;
}