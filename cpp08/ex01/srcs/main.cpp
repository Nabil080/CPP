#include "Span.hpp"

#include <iostream>

int main()
{
	int  numbers[] = {0, 25, 50, 100};
	Span test(4);
	test.fill(numbers, numbers + 4);
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;

	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(0);
	}
	catch (std::length_error e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::length_error e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
