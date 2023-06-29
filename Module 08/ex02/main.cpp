#include "MutantStack.hpp"
#include <iostream>

int main ()
{
    /* MutantStack<int>::iterator i; */


    std::stack<int> b;
    MutantStack<int> a;
    MutantStack<int> c(b);
    a.push(11);
    a.push(44);
    a.push(22);
    std::cout << a.size() << std::endl;
    std::cout << *a.begin();
    std::cout << ++*a.begin();
    std::cout << *a.begin();
    /* i = a.begin(); */
    /* i = a.begin(); */
    /* std::cout << *i-- << std::endl; */
    return 0;
}