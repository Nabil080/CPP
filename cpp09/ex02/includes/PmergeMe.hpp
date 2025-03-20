#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <string>
#include <vector>

#define ERR_RANGE		  "Number outside the valid range (0 - 2147483647)"
#define ERR_NOT_A_NUMBER  "Not a valid number"
#define JACOBSTHAL(level) (pow(2, (level + 1)) + pow(-1, level)) / 3;

class PmergeMe
{
	protected:
		std::string		 _sequence;
		std::vector<int> _vector;
		std::list<int>	 _list;
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
