#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T> class MutantStack : public std::stack<T>
{
/* private:
    T _iterator; */

public:

    MutantStack();
    MutantStack( const std::stack<T> &src);
    MutantStack( const MutantStack<T> &src);
    ~MutantStack();

    T *begin();
    /* class iterator
    {
        public:
        std::stack<T> &_iterator;

        iterator() : _iterator(){}
        iterator &operator++( interator _iterator)
        {
            
        }
        iterator &operator==( std::stack<T> &iterator)
        {
            _iterator = iterator;
        }
    }; */

};

#include "MutantStack.tpp"

#endif
