#include "BitcoinExchange.hpp"

int main( int argc, char **argv )
{
    if(argc != 2)
        std::cout << "Just one argument. It must be a file name." << std::endl;
    else
    {
        std::ifstream inputFile;
        std::ifstream dataFile;
        std::string line;

        BitcoinExchange btc;

        btc.open_file( inputFile, argv[1]);
        while ( getline (inputFile, line) )
            btc.save_line(line);
        btc.open_file( dataFile, "data.csv");
        while ( getline (dataFile, line) )
            btc.saveCsvDate(line);  
        btc.print_data();
        btc.print_csv_data();
        inputFile.close();
    }
    return 0;
}
