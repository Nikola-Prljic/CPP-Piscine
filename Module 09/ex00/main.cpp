#include "BitcoinExchange.hpp"

int main( int argc, char **argv )
{
    if(argc != 2)
        std::cout << "Just one argument. It must be a file name." << std::endl;
    else
    {
        std::ifstream file;
        std::string line;

        BitcoinExchange btc;
        btc.open_file(file, argv[1]);

        while ( getline (file, line) )
        {
            if(btc.valid_line(line) == 0)
                btc.save_date(line);
        }

        btc.print_data();
        file.close();
    }
    return 0;
}
