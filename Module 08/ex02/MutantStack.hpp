#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>
#include <list>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

public:

    MutantStack();
    MutantStack( const MutantStack<T> &src);
    ~MutantStack();

    MutantStack<T> operator=( const MutantStack<T> &src );
    typedef typename Container::iterator iterator;

    iterator begin();
    iterator end();

    iterator begin() const;
    iterator end() const;
};

#include "MutantStack.tpp"

#endif
