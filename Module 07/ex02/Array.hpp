#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
private:
    unsigned int _n;
    T *ptr;
    Array();

public:
    Array( const int &n );
    Array(  Array<T> const &src );
    ~Array();

    T &operator[]( const int &i ) const;
    Array<T> &operator=( Array<T> const &rhs );
    template <typename U>Array<T> &operator=( Array<U> const &rhs );
    int size() const;
    void printArray();
    unsigned int getN() const;
    T * getPtr() const;
};

template<typename T> std::ostream& operator<< (std::ostream& o, const Array <T>& x);

#include "Array.tpp"

#endif