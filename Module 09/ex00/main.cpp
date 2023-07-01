#include "BitcoinExchange.hpp"

int main( int argc, char **argv )
{
    if(argc != 2)
        std::cout << "Just one argument. It must be a file name.";
    else
    {
        BitcoinExchange btc(argv[1]);
    }
    return 0;
}
