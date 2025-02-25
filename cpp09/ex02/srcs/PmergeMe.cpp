#include "PmergeMe.hpp"

#include <climits>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

// constructors

PmergeMe::PmergeMe()
{
	std::cerr << "[PmergeMe default constructor] ! This should never be called !" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) : _list(other._list), _vector(other._vector)
{
	std::cerr << "[PmergeMe copy constructor]" << std::endl;
}

PmergeMe::PmergeMe(std::string sequence)
{
	std::cerr << "[PmergeMe sequence constructor]" << std::endl;

	size_t		pos = 0, start = 0;
	std::string str;
	long		converted;

	while (sequence[pos])
	{
		// go to start
		while (sequence[pos] && std::isspace(sequence[pos]))
			pos++;
		start = pos;
		// go to end
		while (sequence[pos] && std::isspace(sequence[pos]) == 0)
			pos++;
		// convert to int
		str = sequence.substr(start, pos - start);
		converted = std::strtol(str.c_str(), NULL, 10);
		if (converted < 0 || converted > INT_MAX)
			throw(std::range_error(str + " is outside the valid range (0 - 2147483647)"));
		if (converted == 0 && str.empty() == false && str[0] != '0')
			throw(std::runtime_error(str + " is not a valid number"));
		// store
		_list.push_back(converted);
		_vector.push_back(converted);
	}
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
	_vector = other._vector;
	_list = other._list;
	return (*this);
}

// methods

void PmergeMe::sortVector()
{
	;
}

void PmergeMe::sortList()
{
	;
}
