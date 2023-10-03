#include "Serializer.hpp"
#include <stdint.h>

int main( void )
{
    uintptr_t newPtr;
    Data stuff;

    stuff.name = "Niki";
    stuff.age = 26;

    newPtr = Serializer::serialize( &stuff );
    std::cout << Serializer::deserialize(newPtr)->age << std::endl;
    std::cout << Serializer::deserialize(newPtr)->name << std::endl;
    std::cout << newPtr << std::endl;
    return 0;
}