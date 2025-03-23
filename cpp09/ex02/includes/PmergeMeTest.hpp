#ifndef PMERGEMETEST_HPP
#define PMERGEMETEST_HPP

#include "PmergeMe.hpp"

#include <sstream>
#define WHITE "\033[00m"
#define RED	  "\033[31m"
#define GREEN "\033[32m"

class PmergeMeTest : private PmergeMe
{
	private:
		std::string _sequence;
		std::string _error;
		std::string _result;
		std::string _expected_error;
		std::string _expected_result;
		bool		_passed;

		PmergeMeTest();

	public:
		PmergeMeTest(const PmergeMeTest &other);
		PmergeMeTest(std::vector<int> numbers);
		PmergeMeTest(std::string sequence);
		PmergeMeTest(std::string sequence, std::string expected_result);
		~PmergeMeTest();

		PmergeMeTest					 &operator=(const PmergeMeTest &other);

		void							  printTest();
		void							  setError();
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
