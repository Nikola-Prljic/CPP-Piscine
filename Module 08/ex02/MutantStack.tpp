#include "MutantStack.hpp"

template<typename T> MutantStack<T>::MutantStack() : std::stack<T>() {}

template<typename T> MutantStack<T>::MutantStack( const std::stack<T> &src) : std::stack<T>(src) {}

template<typename T> MutantStack<T>::MutantStack( const MutantStack<T> &src) : std::stack<T>(src) {}

template<typename T> MutantStack<T>::~MutantStack() {}

template<typename T> T *MutantStack<T>::begin()
{
    return &std::stack<T>::top();
}