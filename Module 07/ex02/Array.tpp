#ifndef Array_TPP
#define Array_TPP

#include "Array.hpp"
/* template<typename T> Array<T>::Array() : ptr(nullptr), size(0)
{
    return ;
} */



template<typename T> Array<T>::Array( unsigned int n ) : size(n), ptr(new T[n])
{
    std::cout << ">>unsinged int Constructor called" << std::endl;
    for(int i = 0; i < n; i++)
        ptr[i] = 1;
    for(int i = 0; i < n; i++)
        std::cout << ptr[i] << std::endl;
    return ;
}

/* template <typename T> void Array<T>::getArray()
{
    for(int i = 0; i < _n; i++)
        std::cout << ptr[i] << std::endl;
    return ;
} */

/* template <typename T> Array<T>::~Array(){ return ; } */

#endif