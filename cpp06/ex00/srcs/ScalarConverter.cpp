#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

t_type ScalarConverter::getType(std::string literal)
{
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && isascii(literal[1]))
		return (CHAR);
	std::string::const_iterator it = literal.begin();

	if (*it == '+' || *it == '-')
		it++;
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

void ScalarConverter::printChar(char c, long double ld_number)
{
	if (ld_number < std::numeric_limits<char>::min() || ld_number > std::numeric_limits<char>::max())
		std::cout << "char: Overflow\n";
	else if (std::isprint(c) == 0)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'\n";
}

void ScalarConverter::printInt(int nb, long double ld_number)
{
	if (ld_number < std::numeric_limits<int>::min() || ld_number > std::numeric_limits<int>::max())
		std::cout << "int: Overflow\n";
	else
		std::cout << "int: " << nb << "\n";
}

void ScalarConverter::printFloat(float nb, long double ld_number)
{
	std::cout << std::fixed << std::setprecision(1);
	if (ld_number < -std::numeric_limits<float>::max() || ld_number > std::numeric_limits<float>::max())
		std::cout << "float: Overflow\n";
	else
		std::cout << "float: " << nb << "f\n";
}

void ScalarConverter::printDouble(double nb, long double ld_number)
{
	std::cout << std::fixed << std::setprecision(1);
	if (ld_number < -std::numeric_limits<double>::max() || ld_number > std::numeric_limits<double>::max())
		std::cout << "double: Overflow\n";
	else
		std::cout << "double: " << nb << "\n";
}

void ScalarConverter::printNumbers(long double converted_number, long double ld_number)
{
	printChar(static_cast<char>(converted_number), ld_number);
	printInt(static_cast<int>(converted_number), ld_number);
	printFloat(static_cast<float>(converted_number), ld_number);
	printDouble(static_cast<double>(converted_number), ld_number);
}

int ScalarConverter::convert(std::string literal)
{
	if (literal.empty())
		return (0);
	// detect the type
	long double ld_number = std::strtold(literal.c_str(), NULL);
	if (std::isfinite(ld_number) == 0)
		return (0);
	t_type type = getType(literal);
	if (type == NONE)
		return (0);
	// convert to the type
	long double converted_number = 0;
	if (type == CHAR)
		converted_number = static_cast<char>(literal[1]);
	if (type == INT)
		converted_number = atoi(literal.c_str());
	if (type == FLOAT)
		converted_number = std::strtof(literal.c_str(), NULL);
	if (type == DOUBLE)
		converted_number = std::strtod(literal.c_str(), NULL);
	// TODO: explicit conversion to other types, if overflow or impossible display error
	// TODO: display result
	printNumbers(converted_number, ld_number);

	return (1);
}
