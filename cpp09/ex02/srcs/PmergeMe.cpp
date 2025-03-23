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

		if (*(pair_start + jump_to_last_of_elem) > *(next_elem + jump_to_last_of_elem))
			for (int i = 0; i < data.elem_size; i++)
				std::iter_swap(pair_start + i, next_elem + i);
	}
}

bool iterator_comp(iterator left, iterator right)
{
	return *left < *right;
}

void PmergeMe::insertSort(t_data &data)
{
	std::vector<iterator> main;
	std::vector<iterator> pend;

	std::cout << "Elem size : " << data.elem_size << std::endl;

	// NOTE: insert a1, b1 into main
	main.push_back(data.begin + data.elem_size - 1);
	main.push_back(data.begin + data.pair_size - 1);
	// NOTE: insert rest of a's into main
	// insert rest of b's into pend
	for (iterator pair = data.begin + data.pair_size; pair != data.end; std::advance(pair, data.pair_size))
	{
		pend.push_back(pair + data.elem_size - 1);
		main.push_back(pair + data.pair_size - 1);
	}
	// NOTE: insert odd element in pend
	if (data.odd_element)
		pend.push_back(data.end + data.elem_size - 1);

	std::cout << "Main :";
	for (size_t i = 0; i < main.size(); i++)
		std::cout << " " << *(main[i]);
	std::cout << std::endl;
	std::cout << "Pend :";
	for (size_t i = 0; i < pend.size(); i++)
		std::cout << " " << *(pend[i]);
	std::cout << std::endl << std::endl;

	// NOTE: Binary insertion following jacobsthal
	int prev_jacobsthal = JACOBSTHAL(1);
	int inserted_numbers = 0;
	for (int jacobsthal_index = 2;; jacobsthal_index++)
	{
		int curr_jacobsthal = JACOBSTHAL(jacobsthal_index);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		// int offset = 0;

		if (jacobsthal_diff > static_cast<int>(pend.size()))
			break;
		std::cout << "Current jacbosthal : " << curr_jacobsthal << std::endl;
		std::cout << "Diff : " << jacobsthal_diff << std::endl;
		std::vector<iterator>::iterator to_insert = (pend.begin() + jacobsthal_diff - 1);
		std::vector<iterator>::iterator search_bound = (main.begin() + curr_jacobsthal + inserted_numbers);

		for (int insertions_left = jacobsthal_diff; insertions_left > 0; insertions_left--)
		{
			std::cout << "To insert : " << **to_insert << std::endl;
			std::cout << "Bound : " << **(search_bound - 1) << std::endl;

			std::vector<iterator>::iterator pos_to_insert =
				std::upper_bound(main.begin(), search_bound, *to_insert, iterator_comp);
			std::cout << "Position for insertion : " << **pos_to_insert << std::endl;
			std::vector<iterator>::iterator inserted = main.insert(pos_to_insert, *to_insert);
			pend.erase(to_insert);
			(void)inserted;
			to_insert--;

			// break; // temporary cuz trying first loop only
		}

		prev_jacobsthal = curr_jacobsthal;
		// inserted_numbers += jacobsthal_diff;
		// break; // temporary cuz trying first loop only
	}
	std::cout << "Main :";
	for (size_t i = 0; i < main.size(); i++)
		std::cout << " " << *(main[i]);
	std::cout << std::endl;
	std::cout << "Pend :";
	for (size_t i = 0; i < pend.size(); i++)
		std::cout << " " << *(pend[i]);
	std::cout << std::endl << std::endl;

	// NOTE: replace old sequence by main
	data.vec.clear();
	for (std::vector<iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		// NOTE: insert in reversed order since it is the last element
		iterator pair_start = ((*it) - data.elem_size + 1);
		iterator pair_end = (*it) + 1;
		data.vec.insert(data.vec.end(), pair_start, pair_end);
	}
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

	// std::cout << std::endl << "------------- Level " << level << "-------------" << std::endl;
	// printData(data);
	// printPairs(data);

	// std::cout << std::endl << "Level " << level << ": [Merge sorting]" << std::endl << std::endl;
	mergeSort(data);
	// printPairs(data);

	std::cout << "Level " << level << " sequence:";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << " " << vec[i];
	std::cout << std::endl;
	if (data.pair_count > 1)
		mergeInsertSort(vec, level + 1);
	// std::cout << std::endl << "Level " << level << ": [Binary inserting]" << std::endl << std::endl;
	if (level == 2)
		exit(0);
	insertSort(data);
	std::cout << "Level " << level << " sequence after Insertion :";
	for (size_t i = 0; i < data.vec.size(); i++)
		std::cout << " " << data.vec[i];
	std::cout << std::endl;
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
