#include "easyfind.hpp"

int main()
{
    int array[] = {2, 1, 4, 55, 22, 13};
    int n = sizeof(array) / sizeof(array[0]);

    std::vector<int> a(array, array + n);
    if(easyfind(a, 2) == false)
        return 1;
    return 0;
}