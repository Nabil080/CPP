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

PmergeMe::PmergeMe(const PmergeMe &other)
	: _sequence(other._sequence), _vector_data(other._vector_data), _list_data(other._list_data)
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
	data.number_of_pairs = data.sequence.size() / std::pow(2, data.level);
	data.pair_size = std::pow(2, data.level);
	data.remainder_size = data.sequence.size() - (data.number_of_pairs * data.pair_size);
	data.is_odd = data.number_of_pairs % 2;
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
	std::cout << std::endl;
}

void PmergeMe::mergeSort(t_merge_insert_vector &data)
{
	std::cout << "Sorting" << std::endl;

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
		std::cout << "[" << i << "]: ";
		for (size_t j = 0; j < data.pair_size; j++)
			std::cout << _vector_data.sequence[(i * data.pair_size) + j] << " ";
		std::cout << std::endl;
	}
	std::cout << "[Remaining elements] : ";
	for (size_t i = data.number_of_pairs * data.pair_size; i < _vector_data.sequence.size(); i++)
		std::cout << _vector_data.sequence[i] << " ";
	std::cout << std::endl << std::endl;
}

void PmergeMe::insertSort(t_merge_insert_vector &data)
{
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
	for (size_t i = data.pair_size * (data.number_of_pairs - data.is_odd); i < data.pair_size * data.number_of_pairs;
		 i++)
		data.odd.push_back(_vector_data.sequence[i]);
}

std::vector<int> PmergeMe::sortVector()
{
	// starting list
	// pair(merge) and sort max
	// if possible, go deeper
	// last recursive -> start sorting(insert) going back up
	// sort the list -> go back a lvl, this lvl will sort the list -> up to base lvl with sorted list

	static int level = 1;

	initData(_vector_data, level);
	std::cout << std::endl << "vvvvvvvvvvvvv Recursion level " << _vector_data.level << " vvvvvvvvvvvvv" << std::endl;
	printData(_vector_data);
	mergeSort(_vector_data);
	// NOTE: recursion stops when no more pair can be formed
	if (_vector_data.number_of_pairs > 1)
	{
		level++;
		sortVector();
	}
	// NOTE : insert starting from deepest recursion
	std::cout << std::endl << "------------- Level " << level << " going back up -------------" << std::endl;
	printData(_vector_data);
	insertSort(_vector_data);

	// std::cout << "Main : ";
	// for (size_t i = 0; i < data.main.size(); i++)
	// 	std::cout << data.main[i] << " ";
	// std::cout << std::endl;
	// std::cout << "Pend : ";
	// for (size_t i = 0; i < data.pend.size(); i++)
	// 	std::cout << data.pend[i] << " ";
	// std::cout << std::endl;
	// std::cout << "Odd : ";
	// for (size_t i = 0; i < data.odd.size(); i++)
	// 	std::cout << data.odd[i] << " ";
	// std::cout << std::endl;
	// std::cout << "[Remaining elements] : ";
	// for (size_t i = data.number_of_pairs * data.pair_size; i < _vector.size(); i++)
	// 	std::cout << _vector[i] << " ";
	// std::cout << std::endl << std::endl;
	level--;

	// recursion 3 (8elem/pair) n = 0
	// jacob num = (2^(n+1) + (-1)^n) / 3 = 1
	//                          b-1                  a-1
	//
	// main : [2-3-9-13-6-12-7-14] [1-5-10-16-1-4-8-20]
	// pend :
	// odd elem :

	// recursion 2 (4elem/pair) n = 1
	// jacob num = (2^(n+1) + (-1)^n) / 3 = 1
	//                b-1       a-1      a-2
	// main : [1-5-10-16][1-4-8-20][2-3-9-13]
	//                b-2
	// pend : [6-12-7-14] b2 -> look until a2
	//                     b-3
	// odd elem : [11-15-0-19] b-3 -> look whole main
	//
	//                       b-1         a-1      b-2       a-2
	// pend + main : [6-12-7-14][1-5-10-16][1-4-8-20][2-3-9-13]
	//                       b-1         a-1      b-2       a-2         b-3
	// odd + main : [6-12-7-14][1-5-10-16][11-15-0-19][1-4-8-20][2-3-9-13]

	// recursion 1 (2elem/pair) n = 2
	// jacob num = (2^(n+1) + (-1)^n) / 3 = 3
	//           b-1   a-1    a-2   a-3   a-4   a-5
	// main : [6-12][7-14][10-16][0-19][8-20][9-13]
	//          b-2    b-3  b-4  b-5
	// pend : [1-5][11-15][1-4][2-3]
	//
	// odd elem :
	//
	// Jacob num is at 3, we inster 3-1 starting from b3, search up to a-2
	//                b-1   a-1    b-3    a-2   a-3   a-4   a-5
	// b3 + main : [6-12][7-14][11-15][10-16][0-19][8-20][9-13]
	//               b-2   b-1   a-1    b-3    a-2   a-3   a-4   a-5
	// b2 + main : [1-5][6-12][7-14][11-15][10-16][0-19][8-20][9-13]
	//
	// Jacob done
	// recursion 1 (2elem/pair) n = 3
	// jacob num = (2^(n+1) + (-1)^n) / 3 = 5
	//          b-2   b-1   a-1    b-3    a-2   a-3   a-4   a-5
	// main : [1-5][6-12][7-14][11-15][10-16][0-19][8-20][9-13]
	//          b-4  b-5
	// pend : [1-4][2-3]
	//
	// odd elem :
	//
	// Jacob num is at 5, we inster 5-3 starting from b5, search up to a-4
	//                b-5  b-1   a-1    b-3    a-2   a-3   a-4   a-5
	// b5 + main : [2-3][6-12][7-14][11-15][10-16][0-19][8-20][9-13]
	//                b-5 b-4   b-1   a-1    b-3    a-2   a-3   a-4   a-5
	// b4 + main : [2-3][1-4][6-12][7-14][11-15][10-16][0-19][8-20][9-13]
	//
	// Jacob done

	// recursion 0 (1elem/pair) n = 2 (skip 0/1)
	// jacob num = (2^(n+1) + (-1)^n) / 3 = 3
	//       b1a1a2-a3-a4-a5-a6-a7-a9-a8
	// main : 2-3-4-12-14-15-16-19-20
	//      b2-b3-b4-b5-b6-b7-b8
	// pend : 1-6-7-11-10-0-8
	// Jacob num is at 3, we insert 3-1 starting from b3, search up to a-2
	//       b1a1a2-b3-a3-a4-a5-a6-a7-a9-a8
	// b3 + main : 2-3-4-6-12-14-15-16-19-20
	//       b1a1a2-b3-a3-a4-a5-a6-a7-a9-a8
	// b3 + main : 1-2-3-4-6-12-14-15-16-19-20
	//
	// Jacob done

	return (_vector_data.sequence);
}

std::list<int> PmergeMe::sortList()
{
	return (_list_data.sequence);
}
