/* #include "Array.hpp" */
#include "Array.tpp"

int main ( void )
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
        /* a[1] = a[2]; */
        /* copy[3] = a[3]; */
        /* copy.printArray(); */
        a.printArray();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    /* a.getArray(); */
    return (0);
}