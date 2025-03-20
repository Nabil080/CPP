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

PmergeMe::PmergeMe(const PmergeMe &other) : _sequence(other._sequence), _vector_data(other._vector_data), _list_data(other._list_data)
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
	_vector_data = other._vector_data;
	_list_data = other._list_data;
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
		_list_data.sequence.push_back(converted);
		_vector_data.sequence.push_back(converted);
	}

	std::cerr << _vector_data.sequence.size() << " numbers" << std::endl;
}

void PmergeMe::initData(t_merge_insert_vector &data, int level)
{
	data.level = level;
	data.jacob_level = 2;
	data.number_of_pairs = data.sequence.size() / std::pow(2, data.level);
	data.pair_size = std::pow(2, data.level);
	data.remainder_size = data.sequence.size() - (data.number_of_pairs * data.pair_size);
	data.is_odd = data.number_of_pairs % 2;
	data.main.clear();
	data.odd.clear();
	data.pend.clear();
}

void PmergeMe::printData(t_merge_insert_vector &data) const
{
	(void)data;
	std::cout << "Current sequence : ";
	for (size_t i = 0; i < _vector_data.sequence.size(); i++)
		std::cout << _vector_data.sequence[i] << " ";
	std::cout << std::endl;
	std::cout << "Number of elements : " << _vector_data.sequence.size() << std::endl;
	std::cout << "Number of pairs : " << _vector_data.number_of_pairs << std::endl;
	std::cout << "Pair size : " << _vector_data.pair_size << std::endl;
	std::cout << "Remainder size : " << _vector_data.remainder_size << std::endl;
	std::cout << "Is odd : " << _vector_data.is_odd << std::endl;
	for (size_t i = 0; i < _vector_data.number_of_pairs; i++)
	{
		std::cout << "[" << i << "]: ";
		for (size_t j = 0; j < _vector_data.pair_size; j++)
			std::cout << _vector_data.sequence[(i * _vector_data.pair_size) + j] << " ";
		std::cout << std::endl;
	}
	std::cout << "[Remaining elements] : ";
	for (size_t i = _vector_data.number_of_pairs * _vector_data.pair_size; i < _vector_data.sequence.size(); i++)
		std::cout << _vector_data.sequence[i] << " ";
	std::cout << std::endl << std::endl;
}

void PmergeMe::printLists(t_merge_insert_vector &data) const
{
	std::cout << "Main : ";
	for (size_t i = 0; i < data.main.size(); i++)
		std::cout << data.main[i] << " ";
	std::cout << std::endl;
	std::cout << "Pend : ";
	for (size_t i = 0; i < data.pend.size(); i++)
		std::cout << data.pend[i] << " ";
	std::cout << std::endl;
	std::cout << "Odd : ";
	for (size_t i = 0; i < data.odd.size(); i++)
		std::cout << data.odd[i] << " ";
	std::cout << std::endl;
	std::cout << "[Remaining elements] : ";
	for (size_t i = data.number_of_pairs * data.pair_size; i < data.sequence.size(); i++)
		std::cout << data.sequence[i] << " ";
	std::cout << std::endl << std::endl;
}

void PmergeMe::mergeSort(t_merge_insert_vector &data)
{
	// compare pair_size / 2 and pair_size, swap everything before middle
	for (size_t i = 0; i < data.number_of_pairs; i++)
	{
		size_t offset = i * data.pair_size;
		size_t middle = (data.pair_size / 2);
		size_t end = data.pair_size - 1;
		if (_vector_data.sequence[offset + middle - 1] > _vector_data.sequence[offset + end])
		{
			for (size_t j = 0; j < middle; j++)
				std::swap(_vector_data.sequence[offset + j], _vector_data.sequence[offset + middle + j]);
		}
	}
}

void PmergeMe::insertSort(t_merge_insert_vector &data)
{
	// NOTE: initializing starting lists following ford johnson
	std::cout << "=== Starting lists ===" << std::endl;
	for (size_t i = 0; i < data.number_of_pairs - data.is_odd; i++)
	{
		size_t offset = i * data.pair_size;
		// put b1, a1, a2 a.. in main
		if (i == 0 || i % 2 != 0)
			for (size_t j = 0; j < data.pair_size; j++)
				data.main.push_back(_vector_data.sequence[offset + j]);
		// put b2, b3, b4... in pend
		else
			for (size_t j = 0; j < data.pair_size; j++)
				data.pend.push_back(_vector_data.sequence[offset + j]);
		// put odd in odd
	}
	for (size_t i = data.pair_size * (data.number_of_pairs - data.is_odd); i < data.pair_size * data.number_of_pairs; i++)
		data.odd.push_back(_vector_data.sequence[i]);
	printLists(_vector_data);
	// TODO: insert pend into main following jacob algo if possible
	printData(_vector_data);
	size_t jacob = JACOBSTHAL(data.jacob_level);
	size_t to_insert = jacob - JACOBSTHAL(data.jacob_level - 1);

	std::cout << "Jacob : " << jacob << ", level : " << data.jacob_level << std::endl;
	std::cout << "To insert : " << to_insert << std::endl;

	if (data.pend.size() / data.pair_size <= to_insert)
	{
		std::cout << "Not using jacobsthal" << std::endl;
		jacob = 2;
		to_insert = data.pend.size() / data.pair_size;
		std::pair<int, int> range(0, jacob);

		if (data.main.empty() == false)
		{
			std::cout << "Inserting [" << jacob << "] : " << " from " << range.first << " to " << range.second << std::endl;
			size_t middle = (range.second - range.first) / 2;
			int	   num = _vector_data.main[(middle + 1) * data.pair_size - 1];
			std::cout << "Middle[" << middle << "] : " << num << std::endl;
		}
	}
	else
		std::cout << "Using jacobsthal" << std::endl;

	// NOTE: Update sequence using the sorted main
	if (_vector_data.main.empty())
		return;
	for (size_t i = 0; i < _vector_data.main.size(); i++)
		_vector_data.sequence[i] = _vector_data.main[i];
	for (size_t i = 0; i < _vector_data.odd.size(); i++)
		_vector_data.sequence[_vector_data.main.size() + i] = _vector_data.main[i];
	std::cout << "=== Ending list ===" << std::endl;
	printLists(_vector_data);
}

// starting list
// pair(merge) and sort max
// if possible, go deeper
// last recursive -> start sorting(insert) going back up
// sort the list -> go back a lvl, this lvl will sort the list -> up to base lvl with sorted list
std::vector<int> PmergeMe::sortVector()
{
	static int level = 1;

	initData(_vector_data, level);
	std::cout << std::endl << "vvvvvvvvvvvvv Recursion level " << _vector_data.level << " vvvvvvvvvvvvv" << std::endl;
	printData(_vector_data);
	mergeSort(_vector_data);
	std::cout << "=== Sorted ===" << std::endl;
	printData(_vector_data);

	if (_vector_data.number_of_pairs > 1)
	{
		level++;
		sortVector();
	}

	std::cout << std::endl << "------------- Level " << level << " going back up -------------" << std::endl;
	printData(_vector_data);
	insertSort(_vector_data);

	level--;
	initData(_vector_data, level);
	return (_vector_data.sequence);
}

std::list<int> PmergeMe::sortList()
{
	return (_list_data.sequence);
}
