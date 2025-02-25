#ifndef RPN_TEST_HPP
#define RPN_TEST_HPP

#include "RPN.hpp"

#include <string>

class RPN_Test : private RPN
{
	private:
		std::string _input;
		std::string _expected_error;
		int			_expected_result;
		std::string _error;
		int			_result;
		bool		_passed;

	public:
		RPN_Test();
		RPN_Test(const RPN_Test &other);
		RPN_Test(std::string expression, std::string expected_error);
		RPN_Test(std::string expression, int expected_number);
		~RPN_Test();

		RPN_Test &operator=(const RPN_Test &other);

		void	  printTest();
        void    setPassed();
};
#endif
