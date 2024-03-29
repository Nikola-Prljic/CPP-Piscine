#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
#include <stdint.h>

typedef struct Data
{
    std::string name;
    int         age;
}Data;

class Serializer
{
    private:
        Serializer();

    public:
        Serializer( Serializer &rhs );
        ~Serializer();

        Serializer &operator=( Serializer &src);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif