#include "PmergeMe.hpp"

#include <climits>
#include <cstdlib>
#include <iostream>

// constructors

PmergeMe::PmergeMe()
{
	std::cerr << "[PmergeMe default constructor] ! This should never be called !" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) : _sequence(other._sequence), _list(other._list), _vector(other._vector)
{
	std::cerr << "[PmergeMe copy constructor]" << std::endl;
}

PmergeMe::PmergeMe(std::string sequence) : _sequence(sequence)
{
	std::cerr << "[PmergeMe sequence constructor]" << std::endl;
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

void PmergeMe::parseSequence()
{

	size_t		pos = 0, start = 0;
	std::string str;
	long		converted;

	// put inside a template;
	while (_sequence[pos])
	{
		// go to start
		while (_sequence[pos] && std::isspace(_sequence[pos]))
			pos++;
		start = pos;
		// go to end
		while (_sequence[pos] && std::isspace(_sequence[pos]) == 0)
			pos++;
		// convert to int
		str = _sequence.substr(start, pos - start);
		converted = std::strtol(str.c_str(), NULL, 10);
		if (converted < 0 || converted > INT_MAX)
			throw(std::runtime_error(ERR_RANGE));
		if (converted == 0 && str.empty() == false && str[0] != '0')
			throw(std::runtime_error(ERR_NOT_A_NUMBER));
		// store
		_list.push_back(converted);
		_vector.push_back(converted);
	}
}

// 9 8 7 6 5 4 3 2 1 0
std::vector<int> PmergeMe::sortVector()
{
	// [98][76][54][32][10]
	// [89][67][45][23][01]
	// 9 7 5 3 1
	// 8 6 4 2 0
	return (_vector);
}

std::list<int> PmergeMe::sortList()
{
	return (_list);
}
