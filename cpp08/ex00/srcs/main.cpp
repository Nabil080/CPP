#include "easyfind.hpp"
#include <cstddef>
#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> array;

	array.reserve(100);
	for (size_t i = 0; i < 100; i++)
		array.push_back(i);
	for (std::vector<int>::iterator it = array.begin(); it < array.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	test_easyfind(array, 5);
	test_easyfind(array, 50);
	test_easyfind(array, 500);

	return (0);
}
