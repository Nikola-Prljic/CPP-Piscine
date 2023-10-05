#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

void basic_test()
{
    Array<long> num(5);
    for(int i = 0; i < num.size(); i++){
        num[i] = i + 3;
    }
    Array<int> num2(10);
    for(int i = 0; i < num2.size(); i++){
        num2[i] = i + -1;
    }
    num = num2;
    Array<long> num3(num);
    std::cout << num2<< std::endl;
}

int main(int, char**)
{
    basic_test();

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

    for (int i = 0; i < MAX_VAL; i++){
        if (mirror[i] != numbers[i]){
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout << std::endl << "Test for out of range:" << std::endl;
    try{
        numbers[-2] = 0;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    try{
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++){
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}