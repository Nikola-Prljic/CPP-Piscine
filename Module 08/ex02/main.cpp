#include "MutantStack.hpp"
#include <iostream>

#include <typeinfo>


int main ()
{
    /* MutantStack<int>::iterator i; */

    /* MutantStack::iterator<int> it; */
    /* MutantStack<int>::iterator itr;
    MutantStack<int>::iterator itre; */

   /*  std::stack<int> b; */
    MutantStack<int> a;
    MutantStack<int> c(a);
    MutantStack<int>::iterator itr = a.begin();
    a.push(11);
    a.push(44);
    a.push(22);
    a.begin();
    
    c = a;
    MutantStack<int>::iterator itrc = c.begin();
    while(itr != a.end())
    {
        std::cout << itrc[0] << std::endl;
        itr++;
        itrc++;
    }
    /* while(itr != a.end()) */
    /* for(; itr != itre; itr++)
        std::cout << "+" << std::endl; */
    /* std::cout << a.begin() << std::endl; */
    /* std::cout << itr << std::endl; */
    /* for(auto i: a)
        std::cout << i << ' '; */
    /* std::cout << *a.begin();
    std::cout << ++*a.begin();
    std::cout << *a.begin(); */
    /* i = a.begin(); */
    /* i = a.begin(); */
    /* std::cout << *i-- << std::endl; */
    return 0;
}