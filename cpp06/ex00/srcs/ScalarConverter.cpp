#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
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

void ScalarConverter::convert(std::string literal)
{
	if (literal.empty())
		return;
	// TODO: detect the type
	t_type type = getType(literal);
	if (type == CHAR)
		std::cout << "CHAR" << std::endl;
	if (type == INT)
		std::cout << "INT" << std::endl;
	if (type == FLOAT)
		std::cout << "FLOAT" << std::endl;
	if (type == DOUBLE)
		std::cout << "DOUBLE" << std::endl;
	if (type == NONE)
		std::cout << "NONE" << std::endl;
	// TODO: convert to the type
	// TODO: explicit conversion to other types, if overflow or impossible display error
	// TODO: display result

	(void)type;
	(void)literal;
}
