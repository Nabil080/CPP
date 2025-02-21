#include "RPN.hpp"

#include <iostream>
//./RPN "   1 2    * 2 /   2 * 2   4 -   +"
int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		std::cerr << "This program takes an inverted Polish mathematical expression as an argument" << std::endl;
		return (1);
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
