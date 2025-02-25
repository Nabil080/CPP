#include "PmergeMeTest.hpp"

#include <iostream>

void PmergeMeTest::test()
{
	std::cout << "Before:\t";
	for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;

	::PmergeMe::sortList();
	::PmergeMe::sortVector();

	// compare
	return;
}
