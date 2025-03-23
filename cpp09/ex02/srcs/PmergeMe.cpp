#include "PmergeMe.hpp"

// constructors

PmergeMe::PmergeMe()
{
	std::cerr << "[PmergeMe default constructor]" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	std::cerr << "[PmergeMe copy constructor]" << std::endl;
	(void)other;
}

PmergeMe::~PmergeMe()
{
	std::cerr << "[PmergeMe destructor]" << std::endl;
}

// operators

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

// methods

vector PmergeMe::sortVector(std::string sequence)
{
	vector vec = parseSequence<vector>(sequence);
	mergeInsertSort(vec, 1);
	return (vec);
}

deque PmergeMe::sortDeque(std::string sequence)
{
	deque deq = parseSequence<deque>(sequence);
	mergeInsertSort(deq, 1);
	return (deq);
}
