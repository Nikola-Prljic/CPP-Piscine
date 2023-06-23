#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
private:
    const unsigned int _n;
    T *ptr;

public:
    Array();
    Array(unsigned int n);
    ~Array();
    void getArray();
    int size() const;
    T &operator[]( int i );
};

#endif