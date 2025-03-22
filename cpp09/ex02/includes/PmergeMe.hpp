#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <string>
#include <vector>

#define ERR_RANGE		  "Number outside the valid range (0 - 2147483647)"
#define ERR_NOT_A_NUMBER  "Not a valid number"
#define JACOBSTHAL(level) (pow(2, (level + 1)) + pow(-1, level)) / 3;

typedef std::vector<int> vector;
typedef vector::iterator iterator;

class PmergeMe
{
	protected:
		std::string	   _sequence;
		vector		   _vector;
		std::list<int> _list;
		PmergeMe();

	public:
		PmergeMe(const PmergeMe &other);
		PmergeMe(std::string sequence);
		~PmergeMe();

		PmergeMe	  &operator=(const PmergeMe &other);

		vector		   sortVector();
		std::list<int> sortList();
		void		   parseSequence();

	private:
		typedef struct s_data
		{
				vector	 vec;
				int		 level;
				int		 elem_size;
				int		 pair_size;
				int		 pair_count;
				int		 remainder_size;
				bool	 odd_element;
				iterator begin;
				iterator end;
		} t_data;

		void mergeInsertSort(vector &vec, int level);
		void insertSort(t_data &data);
		void mergeSort(t_data &data);
		void printPairs(t_data &data);
		void printData(t_data &data);
		void printElem(vector &vec, t_data &data);
		void printRange(iterator start, iterator end);
};

#endif
