#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

// @return returns an iterator, last if not found
template <typename T> typename T::iterator easyfind(T &container, int needle)
{
	return (std::find(container.begin(), container.end(), needle));
}

// @brief tests easy_find and its return value
template <typename T> void test_easyfind(T &array, int needle)
{
	typename T::iterator found = easyfind(array, needle);
	if (found == array.end())
		std::cout << "Couldn't find " << needle << std::endl;
	else
		std::cout << "Found " << *found << " on index " << std::distance(array.begin(), found) << std::endl;
}

// @brief tests easyfind with a specific container type
template <typename T> void test_container_easyfind(T &array)
{
	for (size_t i = 0; i < 100; i++)
		array.push_back(i);

	std::cout << "Container content : ";
	for (typename T::iterator it = array.begin(); it != array.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	test_easyfind(array, -1234567);
	test_easyfind(array, 5);
	test_easyfind(array, 50);
	test_easyfind(array, 1234567);
}

#endif
