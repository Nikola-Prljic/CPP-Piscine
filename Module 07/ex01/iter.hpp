#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

/* struct Foo
{
    template<typename S>
    void myMethod(S array[]);
};

template void Foo::myMethod(int array[], int len, ); */

/* typedef void (* vFunctionCall)(int &args); */

template <typename T>
void iter(T array[], int len, void(* vFunctionCall)(T &args))
{
    for(int i = 0; i < len; i++)
        vFunctionCall(array[i]);
    return ;
}

#endif