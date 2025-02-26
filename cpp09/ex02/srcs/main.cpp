#include "PmergeMeTest.hpp"

#include <ctime>
#include <iostream>

// Possible errors :
// ERR_RANGE ERR_NOT_A_NUMBER
static void defaultTests()
{
	PmergeMeTest tests[] = {
		PmergeMeTest("-1 -10 0 10 1", ERR_RANGE),
		PmergeMeTest("1 a 2 b 3", ERR_NOT_A_NUMBER),
		PmergeMeTest("9 8 7 6 5 4 3 2 1 0", "0 1 2 3 4 5 6 7 8 9"),
		PmergeMeTest("0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9"),
		PmergeMeTest("0 9 1 8 2 7 3     6 4 5", "0 1 2 3 4 5 6 7 8 9"),
		PmergeMeTest("21474836470 0", ERR_RANGE),
	};

	for (size_t i = 0; i < (sizeof(tests) / sizeof(PmergeMeTest)); i++)
		tests[i].printTest();
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error :" << " usage => ./PmergeMe <positive integer sequence>" << std::endl;
		if (argc != 1)
			return (1);
		std::cout << "No argument given, running default tests" << std::endl << std::endl;
		defaultTests();
		return (0);
	}

	PmergeMe		 merger(argv[1]);
	std::list<int>	 list;
	std::vector<int> vector;
	time_t			 start;

	try
	{
		merger.parseSequence();
		// TODO: sort list and vector and compare time
		std::time(&start);
		merger.sortList();
		std::cout << "List :" << start << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Error :" << e.what() << std::endl;
	}
	return (0);
}
