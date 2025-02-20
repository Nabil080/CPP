
#include "BitcoinExchange.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw(std::runtime_error("Correct usage: ./btc <input_file>"));
		BitcoinExchange input(argv[1]);

		input.printHoldingsValues();
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
