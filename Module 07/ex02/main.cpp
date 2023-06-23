/* #include "Array.hpp" */
#include "Array.tpp"

int main ( void )
{
    unsigned int n = 5;
    Array<int> a(n);

    try
    {
        std::cout << "+" << a[5] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    /* a.getArray(); */
    return (0);
}