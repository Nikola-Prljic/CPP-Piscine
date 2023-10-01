#include "Serializer.hpp"
#include <stdint.h>

int main( void )
{
    Serializer convert;

    uintptr_t newPtr;
    Data stuff;

    stuff.name = "Niki";
    stuff.age = 26;


    newPtr = convert.serialize( &stuff );
    std::cout << convert.deserialize(newPtr)->age << std::endl;
    std::cout << convert.deserialize(newPtr)->name << std::endl;
    std::cout << newPtr << std::endl;
    return 0;
}