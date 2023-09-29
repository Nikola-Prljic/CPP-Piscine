#include "Serializer.hpp"
#include <stdint.h>

int main( void )
{
    uintptr_t newPtr;
    Data stuff;

    stuff.name = "Niki";
    stuff.age = 26;

    Serializer convert;

    newPtr = convert.serialize( &stuff );
    std::cout << convert.deserialize(newPtr)->age << std::endl;
    std::cout << convert.deserialize(newPtr)->name << std::endl;
    std::cout << newPtr << std::endl;
    return 0;
}