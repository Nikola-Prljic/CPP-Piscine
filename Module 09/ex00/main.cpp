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
        /* btc.print_data();
        btc.print_csv_data(); */

        BitcoinExchange::vectorDate::iterator itr = btc._data.begin();
        BitcoinExchange::vectorDate::iterator end = btc._data.end();
        itr = btc.findNextYear( itr, end);

        std::cout << itr->f_ammount;
        /* size_t month_index = btc.findNextMonth( btc._data[0].month, year_index );
        size_t day_index = btc.findNextMonth( btc._data[0].month, month_index );
        std::cout << "found year: " <<  year_index << std::endl;
        std::cout << "found month: " <<  month_index << std::endl;
        std::cout << "found day: " <<  day_index << std::endl;

        std::cout << "result: " << btc._data[0].f_ammount * btc._csv_data[day_index - 1].f_ammount << std::endl; */
        //bug 1 too much at the end with, 2014-04-04 | 1 

        inputFile.close();
    }
    return 0;
}
