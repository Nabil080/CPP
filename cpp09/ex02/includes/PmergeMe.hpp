#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define ERR_RANGE		  "Number outside the valid range (0 - 2147483647)"
#define ERR_NOT_A_NUMBER  "Not a valid number"
#define JACOBSTHAL(level) (pow(2, (level + 1)) + pow(-1, level)) / 3;

typedef std::vector<int> vector;
typedef std::deque<int>	 deque;

class PmergeMe
{
	public:
		PmergeMe(const PmergeMe &other);
		PmergeMe();
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &other);

		vector	  sortVector(std::string sequence);
		deque	  sortDeque(std::string sequence);

	protected:
		template <typename Container> Container parseSequence(std::string sequence)
		{
			Container	container;
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
					throw(std::runtime_error(ERR_RANGE));
				if (converted == 0 && str.empty() == false && str[0] != '0')
					throw(std::runtime_error(ERR_NOT_A_NUMBER));
				// store
				container.push_back(converted);
			}
			return (container);
		}

		template <typename Iterator> void printRange(Iterator start, Iterator end)
		{
			for (Iterator it = start; it != end; it++)
				std::cout << *it << (it + 1 != end ? " " : "");
		}

		template <typename Iterator> void sortPairs(Iterator start, Iterator end, int elem_size)
		{
			for (Iterator current_pair = start; current_pair != end; current_pair += 2 * elem_size)
			{
				Iterator current_last = current_pair + elem_size - 1;
				Iterator next_last = current_last + elem_size;

				if (*current_last > *next_last)
					for (int i = 0; i < elem_size; i++)
						std::iter_swap(current_last - i, next_last - i);
			}
		}

		template <typename Iterator> static bool iterator_comp(Iterator left, Iterator right) { return *left < *right; }

		template <typename Container> void		 mergeInsertSort(Container &container, int level)
		{
			typedef typename Container::iterator Iterator;

			int									 elem_size = std::pow(2, level) / 2;
			int									 pair_size = elem_size * 2;
			int									 pair_count = container.size() / (pair_size);
			bool	 odd_element = ((int)container.size() - (pair_size * pair_count) >= elem_size);
			int		 remainder_size = container.size() % elem_size;
			Iterator pairs_end = container.end() - remainder_size - (odd_element ? elem_size : 0);

			sortPairs(container.begin(), pairs_end, elem_size);

			if (pair_count > 1)
				mergeInsertSort(container, level + 1);

			std::vector<Iterator> main;
			std::vector<Iterator> pend;

			// NOTE: insert a1, b1 into main
			main.push_back(container.begin() + elem_size - 1);
			main.push_back(container.begin() + pair_size - 1);
			// NOTE: insert rest of a's into main
			// insert rest of b's into pend
			for (Iterator pair = container.begin() + pair_size; pair != pairs_end; std::advance(pair, pair_size))
			{
				pend.push_back(pair + elem_size - 1);
				main.push_back(pair + pair_size - 1);
			}
			// NOTE: insert odd element in pend
			if (odd_element)
				pend.push_back(container.end() - remainder_size - 1);

			// NOTE: Binary insertion following jacobsthal
			int prev_jacobsthal = JACOBSTHAL(1);
			int inserted_numbers = 0;
			for (int jacobsthal_index = 2;; jacobsthal_index++)
			{
				int curr_jacobsthal = JACOBSTHAL(jacobsthal_index);
				int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;

				if (jacobsthal_diff > (int)pend.size())
					break;
				typename std::vector<Iterator>::iterator to_insert = (pend.begin() + jacobsthal_diff - 1);
				typename std::vector<Iterator>::iterator search_bound =
					(main.begin() + curr_jacobsthal + inserted_numbers);

				for (int insertions_left = jacobsthal_diff; insertions_left > 0; insertions_left--)
				{
					typename std::vector<Iterator>::iterator pos_to_insert =
						std::upper_bound(main.begin(), search_bound, *to_insert, iterator_comp<Iterator>);

					main.insert(pos_to_insert, *to_insert);
					pend.erase(to_insert--);
					search_bound = (main.begin() + curr_jacobsthal + inserted_numbers);
				}
				prev_jacobsthal = curr_jacobsthal;
				inserted_numbers += jacobsthal_diff;
			}
			for (int i = pend.size() - 1; i >= 0; i--)
			{
				typename std::vector<Iterator>::iterator curr_pend = (pend.begin() + i);
				typename std::vector<Iterator>::iterator curr_bound =
					(main.begin() + main.size() - pend.size() + i + odd_element);
				typename std::vector<Iterator>::iterator pos_to_insert =
					std::upper_bound(main.begin(), curr_bound, *curr_pend, iterator_comp<Iterator>);
				main.insert(pos_to_insert, *curr_pend);
			}

			Container sorted;

			// NOTE: it is last (and highest) number of an element
			// We insert in reserve order to keep the correct order
			for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++)
			{
				Iterator pair_start = ((*it) - elem_size + 1);
				Iterator pair_end = ((*it) + 1);
				sorted.insert(sorted.end(), pair_start, pair_end);
			}
			// NOTE: add the remaining elements at the end (not sorted)
			sorted.insert(sorted.end(), container.end() - remainder_size, container.end());

			container = sorted;
		}
};

#endif
