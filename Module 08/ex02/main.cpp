#include "MutantStack.hpp"
#include <iostream>

/* int main ()
{
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

    int *array;

    array = new int(4);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    int *itrr = &array[0];
    int *itrend = &array[3];
    while(itrr != itrend)
    {
        std::cout << *itrr;
        itrr++;
    }
    return 0;
} */

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "----------" << std::endl;

    {
        std::list<int> mlist;

        mlist.push_back(5);
        mlist.push_back(17);
        std::cout << mlist.back() << std::endl;
        mlist.pop_back();
        std::cout << mlist.size() << std::endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mlist);
    }
return 0;
}