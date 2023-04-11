#include "Cat.hpp"
#include "Dog.hpp"

int main ( void )
{

/*     const Animal* dog = new Dog();
    const Animal* dog2 = new Dog();
    const Animal* cat = new Cat();

    delete dog;
    delete cat; */

    Cat basic;
    {
        Cat tmp = basic;
    }

/*     const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) 
    {
        delete animals[i];
    } */
    return 0;
}