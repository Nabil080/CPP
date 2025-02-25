#include "RPN.hpp"
#include "RPN_TEST.hpp"

#include <iostream>

// Possible errors :
// ERR_EXPRESSION ERR_TOOMANY_OPERATORS ERR_TOOLITTLE_OPERATORS
static void defaultTests()
{
	RPN_Test tests[] = {
		RPN_Test("expression", ERR_EXPRESSION),	   RPN_Test("10 20 +", ERR_EXPRESSION),
		RPN_Test("1 2+3+", ERR_EXPRESSION),		   RPN_Test("1 2 + * 3 4 +", ERR_TOOMANY_OPERATORS),
		RPN_Test("1 + 2", ERR_TOOMANY_OPERATORS),		   RPN_Test("1 2 3 + 4 5 -", ERR_TOOLITTLE_OPERATORS),
		RPN_Test("8 9 * 9 - 9 - 9 - 4 - 1 +", 42), RPN_Test("7 7 * 7 -", 42),
		RPN_Test("1 2 * 2 / 2 * 2 4 - +", 0),	   RPN_Test("(1 + 1)", ERR_EXPRESSION),
	};

	for (size_t i = 0; i < (sizeof(tests) / sizeof(RPN_Test)); i++)
		tests[i].printTest();
}

//./RPN "   1 2    * 2 /   2 * 2   4 -   +"
int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		std::cerr << "This program takes an inverted Polish mathematical expression as an argument" << std::endl;
		std::cout << "No argument given, using default tests" << std::endl;
		defaultTests();
		return (0);
	}

	RPN rpn;
	int result;

	try
	{
		rpn.setExpression(argv[1]);
		result = rpn.getResult();
		std::cout << result << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
