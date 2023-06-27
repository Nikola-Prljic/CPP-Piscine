#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"

template<typename T> int easyfind(T in, int num)
{
    if(std::find(in.begin(), in.end(), num) == in.end())
        return (1);
    return (0);
}

#endif