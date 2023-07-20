#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
        std::cerr << "Error just one argument" << std::endl;
    else
        RPN calc(argv[1]);
}