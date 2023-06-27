#include "Span.hpp"

Span::Span() {}

Span::Span( unsigned int N ) : _value(new int(N)) {}

Span::~Span()
{
    delete _value;
}