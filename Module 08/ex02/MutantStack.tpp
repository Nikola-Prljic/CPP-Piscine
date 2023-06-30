#include "MutantStack.hpp"

template<typename T, typename Container> MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template<typename T, typename Container> MutantStack<T, Container>::MutantStack( const MutantStack<T> &src) : std::stack<T, Container>(src) {}

template<typename T, typename Container> MutantStack<T, Container>::~MutantStack() {}

template<typename T, typename Container> MutantStack<T> MutantStack<T, Container>::operator=( const MutantStack<T> &src ) 
{
    this->c = src.c;
    return *this;
}

template<typename T, typename Container> typename Container::iterator MutantStack<T, Container>::begin() 
{
    return this->c.begin();
}

template<typename T, typename Container> typename Container::iterator MutantStack<T, Container>::end() 
{
    return this->c.end();
}

template<typename T, typename Container> typename Container::iterator MutantStack<T, Container>::begin() const
{
    return this->c.begin();
}

template<typename T, typename Container> typename Container::iterator MutantStack<T, Container>::end() const
{
    return this->c.end();
}