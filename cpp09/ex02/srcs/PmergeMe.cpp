#include "PmergeMe.hpp"

#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iterator>

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

static void printRange(iterator start, iterator end)
{
	for (iterator it = start; it != end; it++)
		std::cout << *it << (it + 1 != end ? " " : "");
}

static void printData(vector &vec, int level)
{
	int		 element_size = std::pow(2, level);
	int		 element_count = vec.size() / element_size;
	int		 remainder_size = vec.size() - element_size * element_count;
	iterator begin = vec.begin(), end = vec.end();

	std::cout << "Sequence = ";
	printRange(begin, end);
	std::cout << std::endl;
	std::cout << "Size = " << vec.size() << std::endl;
	std::cout << "Element_size = " << element_size << std::endl;
	std::cout << "Element_count = " << element_count << std::endl;
	std::cout << "Remainder_size = " << remainder_size << std::endl;
	std::cout << std::endl;
}

static void printElem(vector &vec, int level)
{
	int		 elem_size = std::pow(2, level);
	int		 elem_count = vec.size() / elem_size;
	int		 remainder_size = vec.size() - elem_size * elem_count;
	iterator begin = vec.begin(), end = vec.end();

	for (iterator elem_start = begin; elem_start != end - remainder_size; std::advance(elem_start, elem_size))
	{
		std::cout << "Elem[" << std::distance(begin, elem_start) / elem_size << "]: [";
		printRange(elem_start, elem_start + elem_size / 2);
		std::cout << "] [";
		printRange(elem_start + elem_size / 2, elem_start + elem_size);
		std::cout << "]" << std::endl;
	}

	std::cout << "Remainder: [";
	printRange(end - remainder_size, end);
	std::cout << "]" << std::endl;
}

void mergeSort(vector &vec, int level)
{
	int		 elem_size = std::pow(2, level);
	int		 elem_count = vec.size() / elem_size;
	int		 remainder_size = vec.size() - elem_size * elem_count;
	iterator begin = vec.begin(), end = vec.end();
	int		 jump_to_last_of_elem = elem_size / 2 - 1;

	for (iterator elem_start = begin; elem_start != end - remainder_size; std::advance(elem_start, elem_size))
	{
		iterator elem_half = elem_start + elem_size / 2;

		if (*(elem_start + jump_to_last_of_elem) > *(elem_half + jump_to_last_of_elem))
			for (int i = 0; i < elem_size / 2; i++)
				std::iter_swap(elem_start + i, elem_half + i);
	}
}

void insertSort(vector &vec, int level)
{
	int elem_size = std::pow(2, level);
	int elem_count = vec.size() / elem_size;
	// int		 remainder_size = vec.size() - elem_size * elem_count;
	// iterator begin = vec.begin(), end = vec.end();

	(void)elem_count;
	// initialize main with a1 b1 a2 a3 a4 a5;
}

void mergeInsertSort(vector &vec, int level)
{
	std::cout << std::endl << "------------- Level " << level << "-------------" << std::endl;
	printData(vec, level);
	printElem(vec, level);

	std::cout << std::endl << "Level " << level << ": [Merge sorting]" << std::endl << std::endl;
	mergeSort(vec, level);
	printElem(vec, level);

	const int elem_count = vec.size() / pow(2, level);
	if (elem_count > 1)
		mergeInsertSort(vec, level + 1);

	std::cout << std::endl << "Level " << level << ": [Binary inserting]" << std::endl << std::endl;
	insertSort(vec, level);
}

vector PmergeMe::sortVector()
{
	mergeInsertSort(_vector, 1);
	return (_vector);
}

std::list<int> PmergeMe::sortList()
{
	return (_list);
}
