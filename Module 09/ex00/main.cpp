#include "BitcoinExchange.hpp"

int main( int argc, char **argv )
{
    if(argc == 2)
        BitcoinExchange btc( argv[1] );
    else if( argc == 1 )
        BitcoinExchange btc( "" );
    else
        std::cout << "Just one argument. It must be a file name." << std::endl;
    return (0);
}
