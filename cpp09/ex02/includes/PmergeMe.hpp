#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <string>
#include <vector>

class PmergeMe
{
	protected:
		std::list<int>	 _list;
		std::vector<int> _vector;
		PmergeMe();

	public:
		PmergeMe(const PmergeMe &other);
		PmergeMe(std::string sequence);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &other);

		void	  sortVector();
		void	  sortList();
};

#endif
