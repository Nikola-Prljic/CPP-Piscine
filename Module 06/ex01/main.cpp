#include "Serializer.hpp"

int main( void )
{
    uintptr_t newPtr;
    Data stuff;
    stuff.name = "Niki";
    stuff.age = 26;

    Serializer convert(&stuff);
    std::cout << convert.getPtr()->age << std::endl;

    newPtr = convert.serialize( convert.getPtr() );
    std::cout << convert.deserialize(newPtr)->age << std::endl;
    std::cout << newPtr << std::endl;
    return 0;
}