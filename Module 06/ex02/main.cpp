#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <stdlib.h>

int ft_random()
{
    srand(time(NULL));
    int random_variable = rand() % 3;
    return random_variable;
}

Base * generate( void )
{
    int random_var = ft_random();
    if ( random_var == 0 )
    {
        A *kid_class = new A;
        return dynamic_cast<Base *>(kid_class);
    }
    else if( random_var == 1 )
    {
        B *kid_class = new B;
        return dynamic_cast<Base *>(kid_class);
    }
    else if( random_var == 2 )
    {
        C *kid_class = new C;                                                                                                                                                                                                  
        return dynamic_cast<Base *>(kid_class);
    }
    return NULL;
}

void identify(Base* p)
{
    if ( dynamic_cast< A* >( p ) )
        std::cout << "A" << std::endl;
    else if ( dynamic_cast< B* >( p ) )
        std::cout << "B" << std::endl;
    else if ( dynamic_cast< C* >( p ) )
        std::cout << "C" << std::endl;
    else
        std::cout << "Error: Could not identify class!" << std::endl;
    return ;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast< A& >( p );
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast< B& >( p );
        std::cout << "B" << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast< C& >( p );
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e) {}
    return ;
}

int main ( void )
{
    Base *Base_class_ptr;
    B Bobj;
    B & Bref = Bobj;
    C Cobj;
    C & Cref = Cobj;

    Base_class_ptr = generate();
    if(!Base_class_ptr)
        return (1);
    identify(Base_class_ptr);
    identify(Bref);
    identify(Cref);
    delete Base_class_ptr;
    return (0);
}