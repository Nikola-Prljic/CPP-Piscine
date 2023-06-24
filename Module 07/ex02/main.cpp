/* #include "Array.hpp" */
#include "Array.tpp"
#include <iostream>
#include <stdlib.h>

#define MAX_VAL 750
/* int main ( void )
{
    int n = 5;
    Array<int> a(n);
    Array<int> nix;

    Array<int> copy(a);
    try
    {
        for(int i = 0; i < n; i++)
            a[i] = 22;
        std::cout << a[1];
        a = nix;
        a = copy;
        a.printArray();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    a.getArray();
    return (0);
} */

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}