#include "PmergeMe.hpp"

#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>

// constructors

PmergeMe::PmergeMe()
{
	std::cerr << "[PmergeMe default constructor] ! This should never be called !" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) : _sequence(other._sequence), _vector(other._vector)
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
	return (*this);
}

// methods

void PmergeMe::parseSequence()
{

	size_t		pos = 0, start = 0;
	std::string str;
	long		converted;

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
		_vector.push_back(converted);
		_list.push_back(converted);
	}

	std::cerr << _vector.size() << " numbers" << std::endl;
}

static void printData(std::vector<int> vec, int level)
{
	int element_size = std::pow(2, level);
	int element_count = vec.size() / element_size;
	int remainder_size = vec.size() - element_size * element_count;

	std::cout << std::endl << "------------- Level " << level << "-------------" << std::endl;
	std::cout << "Sequence =";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << " " << vec[i];
	std::cout << std::endl;
	std::cout << "Size = " << vec.size() << std::endl;
	std::cout << "Element_size = " << element_size << std::endl;
	std::cout << "Element_count = " << element_count << std::endl;
	std::cout << "Remainder_size = " << remainder_size << std::endl;
}

void mergeInsertSort(std::vector<int> vec, int level)
{
	int element_size = std::pow(2, level);
	int element_count = vec.size() / element_size;

	printData(vec, level);
	(void)element_count;
	if (element_count > 2)
		mergeInsertSort(vec, level + 1);
}

// starting list
// pair(merge) and sort max
// if possible, go deeper
// last recursive -> start sorting(insert) going back up
// sort the list -> go back a lvl, this lvl will sort the list -> up to base lvl with sorted list
std::vector<int> PmergeMe::sortVector()
{
	mergeInsertSort(_vector, 1);
	return (_vector);
}

std::list<int> PmergeMe::sortList()
{
	return (_list);
}
