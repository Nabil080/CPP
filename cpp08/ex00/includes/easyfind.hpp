#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <cstddef>
#include <iostream>
#include <stdint.h>

// @return SIZE_MAX if not found
template <typename T> size_t easyfind(const T &container, int needle)
{
	for (size_t i = 0; i < container.size(); i++)
		if (container[i] == needle)
			return (container[i]);
	return (SIZE_MAX);
}

template <typename T> void test_easyfind(const T &array, int needle)
{
	size_t index = easyfind(array, needle);
	if (index == SIZE_MAX)
		std::cout << "Couldn't find " << needle << std::endl;
	else
		std::cout << "Found " << needle << " on index " << index << std::endl;
}

#endif
