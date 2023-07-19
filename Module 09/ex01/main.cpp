#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
        return 1;
    RPN calc(argv[1]);
    std::cout << calc.getResult() << std::endl;
}