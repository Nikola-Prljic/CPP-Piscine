#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
private:
    unsigned int _n;
    T *ptr;

public:
    Array();
    Array( int n );
    Array(  Array<T> const &src );
    ~Array();

    T &operator[]( const int i ) const;
    Array<T> &operator=( Array<T> const &rhs);
    int size() const;
    void printArray();
};

template<typename T> std::ostream& operator<< (std::ostream& o, const Array <T>& x);

#include "Array.tpp"

#endif