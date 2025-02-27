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

	std::cerr << _vector.size() << " numbers" << std::endl;
}

std::vector<int> PmergeMe::sortVector()
{
	// starting list
	// pair(merge) and sort max
	// if possible, go deeper
	// last recursive -> start sorting(insert) going back up
	// sort the list -> go back a lvl, this lvl will sort the list -> up to base lvl with sorted list

	// NOTE: variables and base value printing
	static int level = 1;
	size_t	   number_of_pairs = _vector.size() / std::pow(2, level);
	size_t	   pair_size = std::pow(2, level);
	size_t	   remainder_size = _vector.size() - (number_of_pairs * pair_size);

	std::cout << std::endl << "vvvvvvvvvvvvv Recursion level " << level << " vvvvvvvvvvvvv" << std::endl;
	std::cout << "Number of elements : " << _vector.size() << std::endl;
	std::cout << "Number of pairs : " << number_of_pairs << std::endl;
	std::cout << "Pair size : " << pair_size << std::endl;
	std::cout << "Remainder size : " << remainder_size << std::endl;
	for (size_t i = 0; i < number_of_pairs; i++)
	{
		std::cout << "[" << i << "]: ";
		for (size_t j = 0; j < pair_size; j++)
			std::cout << _vector[(i * pair_size) + j] << " ";
		std::cout << std::endl;
	}
	std::cout << "[Remaining elements] : ";
	for (size_t i = number_of_pairs * pair_size; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl << std::endl;

	// NOTE: merge sorting start
	std::cout << "Sorting" << std::endl;

	// compare pair_size / 2 and pair_size, swap everything before middle
	for (size_t i = 0; i < number_of_pairs; i++)
	{
		size_t offset = i * pair_size;
		size_t middle = (pair_size / 2);
		size_t end = pair_size - 1;
		if (_vector[offset + middle - 1] > _vector[offset + end])
		{
			for (size_t j = 0; j < middle; j++)
				std::swap(_vector[offset + j], _vector[offset + middle + j]);
		}
		std::cout << "[" << i << "]: ";
		for (size_t j = 0; j < pair_size; j++)
			std::cout << _vector[(i * pair_size) + j] << " ";
		std::cout << std::endl;
	}
	std::cout << "[Remaining elements] : ";
	for (size_t i = number_of_pairs * pair_size; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl << std::endl;

	// NOTE: recursion stops when no more pair can be formed
	if (number_of_pairs > 1)
	{
		level++;
		sortVector();
	}
	// NOTE : insert starting from deepest recursion

	std::vector<int> main;
	std::vector<int> pend;
	std::vector<int> odd;
	int				 is_odd = number_of_pairs % 2;
	std::cout << std::endl << "------------- Level " << level << " going back up -------------" << std::endl;
	std::cout << "Current sequence : ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
	std::cout << "Number of elements : " << _vector.size() << std::endl;
	std::cout << "Number of pairs : " << number_of_pairs << std::endl;
	std::cout << "Pair size : " << pair_size << std::endl;
	std::cout << "Remain size : " << remainder_size << std::endl;
	std::cout << "Is odd : " << is_odd << std::endl;
	for (size_t i = 0; i < number_of_pairs - is_odd; i++)
	{
		size_t offset = i * pair_size;
		// put b1, a1, a2 a.. in main
		if (i == 0 || i % 2 != 0)
			for (size_t j = 0; j < pair_size; j++)
				main.push_back(_vector[offset + j]);
		// put b2, b3, b4... in pend
		else
			for (size_t j = 0; j < pair_size; j++)
				pend.push_back(_vector[offset + j]);
		// put odd in odd
	}
	for (size_t i = pair_size * (number_of_pairs - is_odd); i < pair_size * number_of_pairs; i++)
		odd.push_back(_vector[i]);
	std::cout << "Main : ";
	for (size_t i = 0; i < main.size(); i++)
		std::cout << main[i] << " ";
	std::cout << std::endl;
	std::cout << "Pend : ";
	for (size_t i = 0; i < pend.size(); i++)
		std::cout << pend[i] << " ";
	std::cout << std::endl;
	std::cout << "Odd : ";
	for (size_t i = 0; i < odd.size(); i++)
		std::cout << odd[i] << " ";
	std::cout << std::endl;
	std::cout << "[Remaining elements] : ";
	for (size_t i = number_of_pairs * pair_size; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl << std::endl;
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

	return (_vector);
}

std::list<int> PmergeMe::sortList()
{
	return (_list);
}
