#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

int ft_random()
{
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;
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
    else
    {
        C *kid_class = new C;
        return dynamic_cast<Base *>(kid_class);
    }
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

void identifya(Base &p)
{
    try
    {
        dynamic_cast< A& >( p );
    }
    catch(const std::exception& e)
    {
        std::string a;
        a = e.what();
        if( a == "std::bad_cast" )
            std::cout << "bad";
    }
    
    /* try
    {
        dynamic_cast< *A >( p );
    } */
    /* if ( dynamic_cast< A& >( p ) )
        std::cout << "A" << std::endl;
    else if ( dynamic_cast< B* >( p ) )
        std::cout << "B" << std::endl;
    else if ( dynamic_cast< C* >( p ) )
        std::cout << "C" << std::endl;
    else
        std::cout << "Error: Could not identify class!" << std::endl; */
    return ;
}

int main ( void )
{
    Base *Base_class_ptr;
    B obj;
    B & ref = obj;

    Base_class_ptr = generate();
    identify(Base_class_ptr);
    identifya(ref);
    delete Base_class_ptr;
    return (0);
}