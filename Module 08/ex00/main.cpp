#include "easyfind.hpp"
#include <vector>

/* int main()
{
    int myints[] = {1, 2, 44, 77};
    std::vector<int> v(myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> empty;

    std::cout << "The contents of fifth are:";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << easyfind(v, 1) << " " << easyfind(empty, 1) << std::endl;
    return (0);
} */

int main()
{
    const int lookFor = 2;
    int array[] = {2, 1, 4, 55, 22, 13};
    int n = sizeof(array) / sizeof(array[0]);
    std::vector<int> num_vector(array, array + n);

    if( easyfind(num_vector, lookFor) == true )
        std::cout << "found: " << lookFor << std::endl;
    return 0;
}