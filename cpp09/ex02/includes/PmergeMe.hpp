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
		typedef struct s_merge_insert_vector
		{
				std::vector<int> sequence;
				int				 level;
				size_t			 number_of_pairs;
				size_t			 pair_size;
				size_t			 remainder_size;
				int				 is_odd;
				std::vector<int> main;
				std::vector<int> pend;
				std::vector<int> odd;
		} t_merge_insert_vector;
		typedef struct s_merge_insert_list
		{
				std::list<int> sequence;
				int			   level;
				size_t		   number_of_pairs;
				size_t		   pair_size;
				size_t		   remainder_size;
				int			   is_odd;
				std::list<int> main;
				std::list<int> pend;
				std::list<int> odd;
		} t_merge_insert_list;

		std::string			  _sequence;
		t_merge_insert_vector _vector_data;
		t_merge_insert_list	  _list_data;
		PmergeMe();

	public:
		PmergeMe(const PmergeMe &other);
		PmergeMe(std::string sequence);
		~PmergeMe();

		PmergeMe		&operator=(const PmergeMe &other);

		void			 parseSequence();
		std::vector<int> sortVector();
		std::list<int>	 sortList();

	private:
		void initData(t_merge_insert_vector &data, int level);
		void initData(t_merge_insert_list &data, int level);
		void printData(t_merge_insert_vector &data) const;
		void printData(t_merge_insert_list &data) const;
		void mergeSort(t_merge_insert_vector &data);
		void insertSort(t_merge_insert_vector &data);
};

#endif
