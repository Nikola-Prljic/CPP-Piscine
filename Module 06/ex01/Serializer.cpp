#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer( Serializer &rhs ) 
{
    *this = rhs;
    return ;
}

Serializer &Serializer::operator=( Serializer &src)
{
    if(this != &src)
        *this = src;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
