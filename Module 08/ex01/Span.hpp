#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
private:
    int *_value;
    Span();

public:
    Span( unsigned int N );
    ~Span();
};

#endif