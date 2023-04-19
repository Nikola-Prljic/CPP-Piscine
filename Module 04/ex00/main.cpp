#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main ( void )
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* koda = new Cat();
    const WrongAnimal* wrong_cat = new WrongCat();
    std::cout << std::endl;

    std::cout << dog->getType() << ":" << std::endl;
    dog->makeSound();
    std::cout << koda->getType() << ":" << std::endl;
    koda->makeSound();
    std::cout << wrong_cat->getType() << ":" << std::endl;
    wrong_cat->makeSound();
    meta->makeSound();
    
    std::cout << std::endl;
    delete koda;
    delete dog;
    delete wrong_cat;
    delete meta;

    return 0;
}
