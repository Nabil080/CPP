#include "PmergeMe.hpp"

#include <iostream>

static int test(std::string sequence)
{
	try
	{
		PmergeMe(sequence).sort();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error :" << e.what() << std::endl;
		return (1);
	}
	return (0);
}

static void defaultTests()
{
	std::string tests[] = {
		"-1 -10 0 10 1",
		"9 8 7 6 5 4 3 2 1 0",
		"0 1 2 3 4 5 6 7 8 9",
		"0 9 1 8 2 7 3     6 4 5",
		"21474836470 0",
	};

	for (size_t i = 0; i < (sizeof(tests) / sizeof(std::string)); i++)
		test(tests[i]);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error :" << " usage => ./PmergeMe <positive integer sequence>" << std::endl;
		if (argc == 1)
		{
			std::cout << "No argument given, running default tests" << std::endl;
			defaultTests();
			return (0);
		}
		return (1);
	}
	return (test(argv[1]));
}
