#ifndef Array_TPP
#define Array_TPP

#include "Array.hpp"

template<typename T> Array<T>::Array() : _n(0), ptr(NULL), index_filled(NULL) {}

template<typename T> Array<T>::Array( unsigned int n ) : _n(n), ptr(new T[n]), index_filled(NULL)
{
    index_filled = new int[_n];
    for(int i = 0; i < (int)n; i++)
        index_filled[i] = false;
    std::cout << ">> unsinged int Constructor called" << std::endl;
}

template<typename T> Array<T>::Array(  Array<T> &src ) : _n(src.size()), ptr(NULL), index_filled(NULL)
{
    if(src.ptr == NULL)
        return ;
    index_filled = new int[src.size()];
    ptr = new T[src.size()];
    for(int i = 0; i < src.size(); i++)
    {
        index_filled[i] = src.index_filled[i];
        if(src.index_filled[i] == true)
            ptr[i] = src[i];
    }
    std::cout << ">> copy assingment constructor called" << std::endl;
}

template <typename T> Array<T>::~Array()
{
    if(ptr != NULL)
        delete [] ptr;
    if(index_filled != NULL)
        delete [] index_filled;
}

template <typename T> int Array<T>::size() const { return _n; }

template <typename T> T &Array<T>::operator[]( int i )
{
    if(ptr == NULL)
        throw std::out_of_range("Error: ptr is NULL");
    if(i < 0)
        throw std::out_of_range("Error: Index must be bigger than 0");
    if(i >= (int)_n)
        throw std::out_of_range("Error: Index is to high");
    index_filled[i] = true;
    /* std::cout << "--"; */
    /* std::cout << "Copy for value called!"<< std::endl; */
    return ptr[i];
}


template <typename T> void Array<T>::printArray()
{
    for(int i = 0; i < (int)_n; i++)
        if(index_filled[i] == true)
            std::cout << ptr[i] << " ";
}

template <typename T> Array<T> &Array<T>::operator=( T value)
{
    value++;
    std::cout << "finish it copy constructor!" << std::endl;
    return *this;
}

template<typename T> std::ostream& operator<< (std::ostream& os, const Array <T>& ar)
{
    os << ar.printArray();
    return os;
}

#endif