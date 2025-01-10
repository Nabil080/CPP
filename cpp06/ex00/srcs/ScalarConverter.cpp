#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

static t_type getType(std::string literal)
{
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && isascii(literal[1]))
		return (CHAR);
	std::string::const_iterator it = literal.begin();

	while (it != literal.end() && std::isdigit(*it))
		it++;
	if (it == literal.end())
		return (INT);
	if (*it != '.')
		return (NONE);
	it++;
	while (it != literal.end() && std::isdigit(*it))
		it++;
	if (it == literal.end())
		return (DOUBLE);
	if (*it == 'f' && it + 1 == literal.end())
		return (FLOAT);
	return (NONE);
}

static void printNumbers(long double number)
{
	std::cout << "Number: " << number << std::endl;
	std::cout << "Errno: " << errno << std::endl;
}

int ScalarConverter::convert(std::string literal)
{
	std::cerr << std::fixed << std::setprecision(1);
	if (literal.empty() || std::isfinite(std::strtold(literal.c_str(), NULL)) == 0)
		return (0);
	// TODO: detect the type
	t_type type = getType(literal);
	if (type == NONE)
		return (0);
	// TODO: convert to the type
	long double number = 0;
	if (type == CHAR)
		number = static_cast<char>(literal[1]);
	if (type == INT)
		number = atoi(literal.c_str());
	if (type == FLOAT)
		number = std::strtof(literal.c_str(), NULL);
	if (type == DOUBLE)
		number = std::strtod(literal.c_str(), NULL);
	// TODO: explicit conversion to other types, if overflow or impossible display error
	// TODO: display result
	printNumbers(number);

	return (1);
}
