#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T array[], const int &len, void(* vFunctionCall)(T &args))
{
    for(int i = 0; i < len; i++)
        vFunctionCall(array[i]);
}

#endif