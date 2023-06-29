#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    using std::stack<T, Container>::c;

/* template<typename T> class MutantStack : public std::stack<T>
{ */
/* private:
    T _iterator; */

public:

    MutantStack();
    MutantStack( const std::stack<T> &src);
    MutantStack( const MutantStack<T> &src);
    ~MutantStack();

    typename std::deque<T>::iterator begin() { return c.begin(); }
    typename std::deque<T>::iterator end() { return c.end(); }

    typename std::deque<T>::iterator begin() const { return c.begin(); }
    typename std::deque<T>::iterator end() const { return c.end(); }

    typename std::deque<T>::iterator operator!=() { return *this; }
    /* T *begin(); */
    class iterator
    {
        public:
        typename std::deque<T>::iterator _itr;

        iterator() : _itr(){}
       /*  iterator &operator++( interator _iterator)
        {
            
        } */
        iterator operator=( typename std::deque<T>::iterator itr)
        {
            _itr = itr;
            return *this;
        }

        typename std::deque<T>::iterator operator++()
        {
            return *this;
        }
    };

};

#include "MutantStack.tpp"

#endif
