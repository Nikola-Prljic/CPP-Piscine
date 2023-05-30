#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

typedef struct Data
{
    std::string name;
    int         age;
}Data;

class Serializer
{
    private:
        static Data* _ptr;
        Serializer();

    public:
        Serializer( Data* ptr );
        ~Serializer();

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

        static Data *getPtr();

};

#endif