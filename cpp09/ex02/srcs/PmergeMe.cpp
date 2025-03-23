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

bool iterator_comp(iterator left, iterator right)
{
	return *left < *right;
}

void PmergeMe::insertSort(t_data &data)
{
	std::vector<iterator> main;
	std::vector<iterator> pend;

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

		if (jacobsthal_diff > (int)pend.size())
			break;
		std::vector<iterator>::iterator to_insert = (pend.begin() + jacobsthal_diff - 1);
		std::vector<iterator>::iterator search_bound = (main.begin() + curr_jacobsthal + inserted_numbers);

		for (int insertions_left = jacobsthal_diff; insertions_left > 0; insertions_left--)
		{

			std::vector<iterator>::iterator pos_to_insert =
				std::upper_bound(main.begin(), search_bound, *to_insert, iterator_comp);
			std::vector<iterator>::iterator inserted = main.insert(pos_to_insert, *to_insert);
			pend.erase(to_insert);
			(void)inserted;
			to_insert--;
			std::cout << "Main :";
			for (size_t i = 0; i < main.size(); i++)
				std::cout << " " << *(main[i]);
			std::cout << std::endl;
			std::cout << "Pend :";
			for (size_t i = 0; i < pend.size(); i++)
				std::cout << " " << *(pend[i]);
			std::cout << std::endl << std::endl;
		}
		prev_jacobsthal = curr_jacobsthal;
	}

	vector sorted;
	sorted.reserve(data.vec.size());

	// NOTE: it is last (and highest) number of an element
	// We insert in reserve order to keep the correct order
	for (std::vector<iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		iterator pair_start = ((*it) - data.elem_size + 1);
		iterator pair_end = ((*it) + 1);
		sorted.insert(sorted.end(), pair_start, pair_end);
	}
	// NOTE: add the remaining elements at the end (not sorted)
	sorted.insert(sorted.end(), data.vec.end() - data.remainder_size, data.vec.end());

	data.vec = sorted;
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

	int jump_to_last_of_elem = data.elem_size - 1;

	std::cout << "--------------------- Merge Sort\n";
	printRange(vec.begin(), vec.end());
	std::cout << "\n";
	iterator pairs_end = vec.end() - data.remainder_size - (data.odd_element ? data.elem_size : 0);
	for (iterator pair_start = vec.begin(); pair_start != pairs_end; std::advance(pair_start, data.pair_size))
	{
		iterator next_elem = pair_start + data.elem_size;

		if (*(pair_start + jump_to_last_of_elem) > *(next_elem + jump_to_last_of_elem))
			for (int i = 0; i < data.elem_size; i++)
				std::iter_swap(pair_start + i, next_elem + i);
	}
	printRange(vec.begin(), vec.end());
	std::cout << "\n--------------------- Merge Sort\n";

	if (data.pair_count > 1)
		mergeInsertSort(vec, level + 1);
	// return;

	// if (level == 1)
	// 	exit(0);

	std::cout << "--------------------- Insertion Sort\n\n";

	std::cout << "Recursion Level " << level << ", starting sequence :\n";
	printRange(vec.begin(), vec.end());
	std::cout << "\nElement size : " << data.elem_size << std::endl << std::endl;

	std::vector<iterator> main;
	std::vector<iterator> pend;

	// NOTE: insert a1, b1 into main
	main.push_back(vec.begin() + data.elem_size - 1);
	main.push_back(vec.begin() + data.pair_size - 1);
	// NOTE: insert rest of a's into main
	// insert rest of b's into pend
	for (iterator pair = vec.begin() + data.pair_size; pair != pairs_end; std::advance(pair, data.pair_size))
	{
		pend.push_back(pair + data.elem_size - 1);
		main.push_back(pair + data.pair_size - 1);
	}
	// NOTE: insert odd element in pend
	if (data.odd_element)
		pend.push_back(vec.end() - data.remainder_size - 1);

	// NOTE: Binary insertion following jacobsthal
	int prev_jacobsthal = JACOBSTHAL(1);
	int inserted_numbers = 0;
	for (int jacobsthal_index = 2;; jacobsthal_index++)
	{
		int curr_jacobsthal = JACOBSTHAL(jacobsthal_index);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;

		if (jacobsthal_diff > (int)pend.size())
			break;
		std::vector<iterator>::iterator to_insert = (pend.begin() + jacobsthal_diff - 1);
		std::vector<iterator>::iterator search_bound = (main.begin() + curr_jacobsthal + inserted_numbers);

		for (int insertions_left = jacobsthal_diff; insertions_left > 0; insertions_left--)
		{

			std::cout << "Main :";
			for (size_t i = 0; i < main.size(); i++)
				std::cout << " " << *(main[i]);
			std::cout << std::endl;
			std::cout << "Pend :";
			for (size_t i = 0; i < pend.size(); i++)
				std::cout << " " << *(pend[i]);
			std::cout << std::endl;

			std::cout << "To insert : " << **to_insert << std::endl;
			std::cout << "Search bound : " << (search_bound != main.end() ? **search_bound : 0) << std::endl;
			std::vector<iterator>::iterator pos_to_insert =
				std::upper_bound(main.begin(), search_bound, *to_insert, iterator_comp);
			std::cout << "Pos found : " << **pos_to_insert << std::endl;
			std::vector<iterator>::iterator inserted = main.insert(pos_to_insert, *to_insert);

			pend.erase(to_insert);
			(void)inserted;
			to_insert--;
			search_bound = (main.begin() + curr_jacobsthal + inserted_numbers);
			std::cout << std::endl;
		}
		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
	}
	/* Insert the remaining elements in the reversed order. Here we also want to
	   perform as less comparisons as possible, so we calculate the starting bound
	   to insert pend number to be the pair of the first pend number. If the first
	   pend number is b8, the bound is a8, if the pend number is b7, the bound is a7 etc.
	   With the way I do it the index of bound is
	   size_of_main - size_of_pend + index_of_current_pend. */
	for (ssize_t i = pend.size() - 1; i >= 0; i--)
	{
		std::vector<iterator>::iterator curr_pend = (pend.begin() + i);
		std::vector<iterator>::iterator curr_bound = (main.begin() + main.size() - pend.size() + i + data.odd_element);
		std::vector<iterator>::iterator pos_to_insert =
			std::upper_bound(main.begin(), curr_bound, *curr_pend, iterator_comp);
		main.insert(pos_to_insert, *curr_pend);
		std::cout << "Main :";
		for (size_t ij = 0; ij < main.size(); ij++)
			std::cout << " " << *(main[ij]);
		std::cout << std::endl;
		std::cout << "Pend :";
		for (size_t ij = 0; ij < pend.size(); ij++)
			std::cout << " " << *(pend[ij]);
		std::cout << std::endl << std::endl;
	}

	vector sorted;
	sorted.reserve(vec.size());

	// NOTE: it is last (and highest) number of an element
	// We insert in reserve order to keep the correct order
	for (std::vector<iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		iterator pair_start = ((*it) - data.elem_size + 1);
		iterator pair_end = ((*it) + 1);
		sorted.insert(sorted.end(), pair_start, pair_end);
	}
	// NOTE: add the remaining elements at the end (not sorted)
	sorted.insert(sorted.end(), vec.end() - data.remainder_size, vec.end());

	vec = sorted;
	std::cout << "Recursion Level " << level << ", ending sequence :\n";
	printRange(vec.begin(), vec.end());
	std::cout << "\n\n--------------------- Insertion Sort\n";
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
