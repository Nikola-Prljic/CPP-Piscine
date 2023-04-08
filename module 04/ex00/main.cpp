#include "Cat.hpp"
#include "Dog.hpp"

int main ( void )
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* koda = new Cat();
    std::cout << std::endl;

    std::cout << dog->getType() << ":" << std::endl;
    dog->makeSound();
    std::cout << koda->getType() << ":" << std::endl;
    koda->makeSound();
    meta->makeSound();
    
    std::cout << std::endl;
    delete koda;
    delete meta;
    delete dog;
    return 0;
}