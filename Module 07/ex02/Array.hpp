#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
private:
    const unsigned int _n;
    T *ptr;
    int *index_filled;

public:
    Array();
    Array( unsigned int n );
    Array(  Array<T> &src );
    ~Array();

    void printArray();
    int size() const;
    T &operator[]( int i );
    Array<T> &operator=( T value);

};


template<typename T> std::ostream& operator<< (std::ostream& o, const Array <T>& x);

#endif