#ifndef Array_TPP
# define Array_TPP

# include "Array.hpp"

template<typename T> Array<T>::Array() : _n(0), ptr(NULL){}

template<typename T> Array<T>::Array( int n ) : _n(n), ptr(new T[n]){}

template<typename T> Array<T>::Array(  Array<T> const &src ) : _n(src.size()), ptr(NULL)
{
    if(src.ptr == NULL)
        return ;
    ptr = new T[src.size()];
    for(int i = 0; i < src.size(); i++)
        ptr[i] = src[i];
    std::cout << ">> copy assingment constructor called" << std::endl;
}

template <typename T> Array<T>::~Array()
{
    if(ptr != NULL)
        delete [] ptr;
}

template <typename T> int Array<T>::size() const { return _n; }

template <typename T> Array<T> &Array<T>::operator=( Array<T> const &rhs )
{
    if(rhs.ptr == NULL)
        return *this;
    _n = rhs._n;
    std::cout << "+" << std::endl;
    if(ptr != NULL)
        delete [] ptr;
    ptr = new T[rhs.size()];
    for(int i = 0; i < rhs.size(); i++)
        ptr[i] = rhs[i];
    return *this;
}

template <typename T> T &Array<T>::operator[]( int i ) const
{
    if(ptr == NULL)
        throw std::out_of_range("Error: ptr is NULL");
    if(i < 0 || i >= (int)_n)
        throw std::out_of_range("Error: out of bounds");
    return ptr[i];
}

template <typename T> void Array<T>::printArray()
{
    for(int i = 0; i < (int)_n; i++)
    {
        std::cout << ptr[i];
        if(i + 1 != (int)_n)
            std::cout << " ";
    }
}

template<typename T> std::ostream& operator<< (std::ostream& os, const Array <T>& ar)
{
    for(int i = 0; i < ar.size(); i++)
    {
        os << ar[i];
        std::cout << ar[i];
        if(i + 1 != ar.size())
            os << " ";
    }
    return os;
}

#endif