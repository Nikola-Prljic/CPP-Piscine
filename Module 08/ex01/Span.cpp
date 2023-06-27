#include "Span.hpp"

Span::Span() {}

Span::Span( unsigned int N ) : _N(N), _value(), _sorted(), is_sorted(false) {}

Span::~Span() {}

void Span::addNumber( int num )
{
    if(_value.size() >= _N)
        throw std::out_of_range("Span: Full, can't add more");
    _value.push_back(num);
    is_sorted = false;
}

void is_stack_to_small(std::vector<int> _value)
{
    if(_value.empty() == true || _value.size() == 1)
        throw std::logic_error("Span: stack to small");
}

int Span::longestSpan()
{
    is_stack_to_small(_value);
    if(is_sorted == false)
    {
        _sorted = _value;
        std::sort(_sorted.begin(), _sorted.end());
        is_sorted = true;
    }
    return _sorted.back() - _sorted.front();
}

int Span::shortestSpan()
{
    is_stack_to_small(_value);
    if(is_sorted == false)
    {
        _sorted = _value;
        std::sort(_sorted.begin(), _sorted.end());
        is_sorted = true;
    }
    return _sorted[1] - _sorted.front();
}

/* int Span::longestSpan()
{
    std::vector<int> tmp;

    tmp = _value;
    std::sort(tmp.begin(), tmp.end());
    return tmp.back() - tmp.front();
} */