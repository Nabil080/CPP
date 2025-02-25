#ifndef PMERGEMETEST_HPP
#define PMERGEMETEST_HPP

#include "PmergeMe.hpp"

#include <list>
#include <vector>

class PmergeMeTest : private PmergeMe
{
	private:
		std::vector<int> _expected_vector;
		std::list<int>	 _expected_list;
		std::string		 _expected_error;
		bool			 passed;

	public:
		void test();
};

#endif // !PMERGEMETEST_HPP
