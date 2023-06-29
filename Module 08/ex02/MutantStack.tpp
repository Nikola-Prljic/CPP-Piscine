#include "MutantStack.hpp"

template<typename T, typename Container> MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template<typename T, typename Container> MutantStack<T, Container>::MutantStack( const std::stack<T> &src) : std::stack<T>(src) {}

template<typename T, typename Container> MutantStack<T, Container>::MutantStack( const MutantStack<T> &src) : std::stack<T>(src) {}

template<typename T, typename Container> MutantStack<T, Container>::~MutantStack() {}

/* template<typename T, typename Container> MutantStack<T, Container> T *MutantStack<T>::begin()
{
    return &std::stack<T>::top();
} */

//template<typename T> iterator &MutantStack::iterator::operator++( interator _iterator )