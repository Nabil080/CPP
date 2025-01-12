#include "easyfind.hpp"
#include <cstddef>
#include <iostream>
#include <vector>

static void vector_test()
{
	std::vector<int> array;

	array.reserve(100);
	for (size_t i = 0; i < 100; i++)
		array.push_back(i);

	std::cout << "Vector content : ";
	for (std::vector<int>::iterator it = array.begin(); it < array.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	test_easyfind(array, 5);
	test_easyfind(array, 50);
	test_easyfind(array, 500);
}

int main(void)
{
	vector_test();

	return (0);
}
