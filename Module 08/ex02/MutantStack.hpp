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
    class iterator
    {
        T *_iterator;
    };

};



#include "MutantStack.tpp"

#endif
