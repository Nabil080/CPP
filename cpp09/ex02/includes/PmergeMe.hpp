#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <string>
#include <vector>

#define ERR_RANGE		 "Number outside the valid range (0 - 2147483647)"
#define ERR_NOT_A_NUMBER "Not a valid number"

class PmergeMe
{
	protected:
		std::string		 _sequence;
		std::list<int>	 _list;
		std::vector<int> _vector;
		PmergeMe();

	public:
		PmergeMe(const PmergeMe &other);
		PmergeMe(std::string sequence);
		~PmergeMe();

		PmergeMe		&operator=(const PmergeMe &other);

		void			 parseSequence();
		std::vector<int> sortVector();
		std::list<int>	 sortList();
};

#endif
