#include "Span.hpp"

Span::Span() {}

Span::Span( const unsigned int &N ) : _N(N), _span(), _sorted(), is_sorted(false) {}

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

void Span::addNumber( const int &num )
{
    if(_span.size() >= _N)
        throw std::out_of_range("Span: Full, can't add more");
    _span.push_back(num);
    is_sorted = false;
}

void Span::addNumber( std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    if ( _span.size() >= _N || _span.size() + (end - begin) > _N)
        throw std::out_of_range("Span: Full, can't add more");
    _span.insert( _span.end(), begin, end );
}

void Span::sort_span()
{
    if(_span.empty() == true || _span.size() == 1)
        throw std::logic_error("Span: to small");
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
    int span = -1;
    for(size_t i = 0; i < (_sorted.size() - 1); i++)
        if(_sorted[i + 1] - _sorted[i] < span || span == -1)
            span = _sorted[i + 1] - _sorted[i];
    return span;
}

std::vector<int> Span::getSpan() const { return _span; }

unsigned int Span::getN() const { return _N; }

std::ostream &operator<<( std::ostream& os, const Span &src)
{
    std::vector<int> tmp = src.getSpan();
    for(std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
        os << it[0] << " ";
    return os;
}