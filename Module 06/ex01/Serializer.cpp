#include "Serializer.hpp"

Data *Serializer::_ptr{ NULL };

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer( Data* ptr )
{
    _ptr = ptr;
    return ;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

Data *Serializer::getPtr() { return _ptr; }