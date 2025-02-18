#include "easyfind.hpp"

#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	std::vector<int> vector;
	std::cout << "--- Testing vector ---" << std::endl << std::endl;
	test_container_easyfind(vector);
	std::cout << std::endl;
	std::list<int> list;
	std::cout << "--- Testing list ---" << std::endl << std::endl;
	test_container_easyfind(list);
	std::cout << std::endl;

	return (0);
}
