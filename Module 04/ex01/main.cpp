#include "Cat.hpp"
#include "Dog.hpp"

int main ( void )
{

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    delete dog;
    delete cat;


    const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) 
        delete animals[i];

    Cat c;
    Cat tmp_c = c;

    Dog d;
    Dog tmp_d = d;

    Dog basic;
    {
        Dog tmp = basic;
    }

    return 0;
}