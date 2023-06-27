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
    int array[] = {2, 1, 4, 55, 22, 13};
    int n = sizeof(array) / sizeof(array[0]);

    std::vector<int> a(array, array + n);
    if(easyfind(a, 2) == false)
        return 1;
    return 0;
}