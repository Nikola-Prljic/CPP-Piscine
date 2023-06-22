#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
private:
    unsigned int size;
    T *ptr;

public:
    /* Array(); */
    Array(unsigned int n);
    /* ~Array(); */
    /* void getArray(); */
};

#endif