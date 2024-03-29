#include "iter.hpp"
#include <string.h>

void more(char &i)
{
    i += 1;
}

void more(int &i)
{
    i += 1;
}

void TestIter(std::string array)
{
    std::cout << "c_str: ";

    iter((char *)array.c_str(), 4, more);
    if(array == "2345")
        std::cout << "OK" << std::endl;
    else
        std::cout << "KO" << std::endl;
}

void TestIter(char array[])
{
    std::cout << "array: ";

    iter(array, 4, more);
    for ( int i = 0; i < 4; i++ )
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

void TestIter(int array[])
{
    std::cout << "int_a: ";

    iter(array, 4, more);
    if(array[0] + array[1] + array[2] + array[3] == 14)
        std::cout << "OK" << std::endl;
    else
        std::cout << "KO" << std::endl;
}

int main ( void )
{
    std::string array1= "1234";
    char array2[] = {'1', '2', '3', '4'};
    int array3[] = {1, 2, 3, 4};

    TestIter(array1);
    TestIter(array2);
    TestIter(array3);
    return (0);
}

/* #include"iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
} */