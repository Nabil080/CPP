#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define ERR_RANGE		  "Number outside the valid range (0 - 2147483647)"
#define ERR_NOT_A_NUMBER  "Not a valid number"
#define JACOBSTHAL(level) (pow(2, (level + 1)) + pow(-1, level)) / 3;

typedef std::vector<int> vector;

class PmergeMe
{
	protected:
		std::string		_sequence;
		vector			_vector;
		std::deque<int> _deque;
		PmergeMe();

	public:
		PmergeMe(const PmergeMe &other);
		PmergeMe(std::string sequence);
		~PmergeMe();

		PmergeMe	   &operator=(const PmergeMe &other);

		vector			sortVector();
		std::deque<int> sortdeque();
		void			parseSequence();

	private:
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

			std::cout << "--------------------- Merge Sort\n";
			printRange(container.begin(), container.end());
			std::cout << "\n";
			sortPairs(container.begin(), pairs_end, elem_size);
			printRange(container.begin(), container.end());
			std::cout << "\n--------------------- Merge Sort\n";

			if (pair_count > 1)
				mergeInsertSort(container, level + 1);
			std::cout << "--------------------- Insertion Sort\n\n";

			std::cout << "Recursion Level " << level << ", starting sequence :\n";
			printRange(container.begin(), container.end());
			std::cout << "\nElement size : " << elem_size << std::endl << std::endl;

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
					typename std::vector<Iterator>::iterator pos_to_insert =
						std::upper_bound(main.begin(), search_bound, *to_insert, iterator_comp<Iterator>);
					std::cout << "Pos found : " << **pos_to_insert << std::endl;
					typename std::vector<Iterator>::iterator inserted = main.insert(pos_to_insert, *to_insert);

					pend.erase(to_insert);
					(void)inserted;
					to_insert--;
					search_bound = (main.begin() + curr_jacobsthal + inserted_numbers);
					std::cout << std::endl;
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
				std::cout << "Main :";
				for (size_t ij = 0; ij < main.size(); ij++)
					std::cout << " " << *(main[ij]);
				std::cout << std::endl;
				std::cout << "Pend :";
				for (size_t ij = 0; ij < pend.size(); ij++)
					std::cout << " " << *(pend[ij]);
				std::cout << std::endl << std::endl;
			}

			Container sorted;
			sorted.reserve(container.size());

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
			std::cout << "Recursion Level " << level << ", ending sequence :\n";
			printRange(container.begin(), container.end());
			std::cout << "\n\n--------------------- Insertion Sort\n";
		}
};

#endif
