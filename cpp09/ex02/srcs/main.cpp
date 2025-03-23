#include "PmergeMeTest.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

static std::vector<int> fillNumbers(size_t size)
{
	std::vector<int> numbers;
	numbers.reserve(size);

	for (size_t i = 0; i < numbers.capacity(); i++)
		numbers.push_back(i);
	std::random_shuffle(numbers.begin(), numbers.end());
	return (numbers);
}

static std::vector<int> generateRandomNumbers(size_t size)
{
	std::vector<int> numbers;
	numbers.reserve(size);

	srand(time(0));
	for (size_t i = 0; i < numbers.capacity(); i++)
		numbers.push_back(rand());
	return (numbers);
}

static void defaultTests()
{
	PmergeMeTest tests[] = {
		PmergeMeTest("-1 -10 0 10 1", ERR_RANGE),
		PmergeMeTest("21474836470 0", ERR_RANGE),
		PmergeMeTest("1 a 2 b 3", ERR_NOT_A_NUMBER),
		PmergeMeTest("3   4   2   1   0", "0 1 2 3 4"),
		PmergeMeTest(fillNumbers(10)),
		PmergeMeTest(generateRandomNumbers(100)),
		// PmergeMeTest(generateRandomNumbers(1000)),
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

	PmergeMeTest pm(argv[1]);
	pm.printTest();

	return (0);
}
