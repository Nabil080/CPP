#ifndef PMERGEMETEST_HPP
#define PMERGEMETEST_HPP

#include "PmergeMe.hpp"

#include <sstream>

class PmergeMeTest : private PmergeMe
{
	private:
		std::string _error;
		std::string _result;
		std::string _expected_error;
		std::string _expected_result;
		bool		_passed;

		PmergeMeTest();

	public:
		PmergeMeTest(const PmergeMeTest &other);
		PmergeMeTest(std::string sequence, std::string expected_result);
		~PmergeMeTest();

		PmergeMeTest					 &operator=(const PmergeMeTest &other);

		void							  printTest();
		void							  setPassed();
		template <typename T> std::string containerToString(T container)
		{
			std::ostringstream	 result;
			typename T::iterator it = container.begin();

			while (it != container.end())
			{
				result << *it;
				it++;
				if (it != container.end())
					result << " ";
			}
			return (result.str());
		}
};

#endif // !PMERGEMETEST_HPP
