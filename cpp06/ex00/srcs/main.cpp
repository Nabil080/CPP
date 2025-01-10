#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2 || ScalarConverter::convert(argv[1]) == 0)
	{
		std::cout << "Please give a single valid literal as an argument" << std::endl;
		return (1);
	}
	return (0);
}
