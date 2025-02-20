
#include "BitcoinExchange.hpp"

#include <iostream>
#include <stdexcept>
int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw(std::runtime_error("Correct usage: ./btc <input_file>"));
		BitcoinExchange data("data.csv", ',');
		BitcoinExchange input(argv[1]);
		// std::cout << data << std::endl;
		std::cout << input << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
