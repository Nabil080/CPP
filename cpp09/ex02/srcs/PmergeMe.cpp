#include "PmergeMe.hpp"

#include <algorithm>
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

void PmergeMe::printRange(iterator start, iterator end)
{
	for (iterator it = start; it != end; it++)
		std::cout << *it << (it + 1 != end ? " " : "");
}

void PmergeMe::printElem(vector &vec, t_data &data)
{
	for (iterator elem_start = vec.begin(); elem_start < vec.end(); std::advance(elem_start, data.elem_size))
	{
		std::cout << "Elem[" << std::distance(vec.begin(), elem_start) / data.elem_size << "]: [";
		printRange(elem_start, elem_start + data.elem_size);
		std::cout << "]" << std::endl;
	}
}

void PmergeMe::printData(t_data &data)
{
	std::cout << "Sequence = ";
	printRange(data.begin, data.end);
	std::cout << std::endl;
	std::cout << "Size = " << data.vec.size() << std::endl;
	std::cout << "Element_size = " << data.elem_size << std::endl;
	std::cout << "Pair_size = " << data.pair_size << std::endl;
	std::cout << "Pair_count = " << data.pair_count << std::endl;
	std::cout << "Odd_element = " << data.odd_element << std::endl;
	std::cout << "Remainder_size = " << data.remainder_size << std::endl;
	std::cout << std::endl;
}

void PmergeMe::printPairs(t_data &data)
{
	for (iterator pair_start = data.begin; pair_start != data.end; std::advance(pair_start, data.pair_size))
	{
		std::cout << "Pair[" << std::distance(data.begin, pair_start) / data.pair_size << "]: [";
		printRange(pair_start, pair_start + data.elem_size);
		std::cout << "] [";
		printRange(pair_start + data.elem_size, pair_start + data.pair_size);
		std::cout << "]" << std::endl;
	}
	std::cout << "Odd_element: [";
	if (data.odd_element)
		printRange(data.end - data.elem_size, data.end);
	std::cout << "]" << std::endl;

	std::cout << "Remainder: [";
	if (data.remainder_size)
		printRange(data.end, data.vec.end());
	std::cout << "]" << std::endl;
}

void PmergeMe::mergeSort(t_data &data)
{
	int jump_to_last_of_elem = data.elem_size - 1;

	for (iterator pair_start = data.begin; pair_start != data.end; std::advance(pair_start, data.pair_size))
	{
		iterator next_elem = pair_start + data.elem_size;
		std::cout << "Start = " << *pair_start << ", next_elem = " << *next_elem << ", next_pair = " << *(pair_start + data.pair_size) << std::endl;

		if (*(pair_start + jump_to_last_of_elem) > *(next_elem + jump_to_last_of_elem))
			for (int i = 0; i < data.elem_size; i++)
				std::iter_swap(pair_start + i, next_elem + i);
	}
}

void PmergeMe::insertSort(t_data &data)
{
	vector main;
	vector pend;

	// NOTE: main and pend initialization
	// mend : (a1, b1, b2, b3..), pend : (a2, a3, a4...)
	main.insert(main.end(), data.begin, data.begin + data.pair_size);
	for (iterator pair_start = data.begin + data.pair_size; pair_start != data.end - data.remainder_size; std::advance(pair_start, data.pair_size))
	{
		iterator next_elem = pair_start + data.elem_size;
		iterator pair_end = pair_start + data.pair_size;

		main.insert(main.end(), next_elem, pair_end);
		pend.insert(pend.end(), pair_start, next_elem);
	}

	std::cout << "-- MAIN --" << std::endl;
	printElem(main, data);
	std::cout << "-- PEND --" << std::endl;
	printElem(pend, data);

	// NOTE: binary insertion start
	while (pend.empty() == false)
	{
		// calculate jacobsthal number
		// binary insert based on jacobsthal and using range
		// binary insert the rest
	}

	// NOTE: Update sequence with main
	std::copy(main.begin(), main.end(), data.vec.begin());
}

void PmergeMe::mergeInsertSort(vector &vec, int level)
{
	t_data data;

	data.vec = vec;
	data.level = level;
	data.elem_size = std::pow(2, level) / 2;
	data.pair_size = data.elem_size * 2;
	data.pair_count = vec.size() / (data.pair_size);
	data.odd_element = ((int)vec.size() - (data.pair_size * data.pair_count) >= data.elem_size);
	data.remainder_size = vec.size() % data.elem_size;
	data.begin = vec.begin();
	data.end = vec.end() - data.remainder_size - data.elem_size * data.odd_element;

	std::cout << std::endl << "------------- Level " << level << "-------------" << std::endl;
	printData(data);
	printPairs(data);

	std::cout << std::endl << "Level " << level << ": [Merge sorting]" << std::endl << std::endl;
	mergeSort(data);
	printPairs(data);

	if (data.pair_count > 1)
		mergeInsertSort(vec, level + 1);

	std::cout << std::endl << "Level " << level << ": [Binary inserting]" << std::endl << std::endl;
	insertSort(data);
	if (level == 3)
		exit(0);
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
