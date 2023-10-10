#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T> int easyfind( const T &src, const int &i )
{
    if( std::find(src.begin(), src.end(), i) == src.end() )
        return *src.end();
    return i;
}

#endif