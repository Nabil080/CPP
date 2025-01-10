#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

static bool isChar(std::string literal)
{
	if (literal.length() != 3)
		return (false);
	if (literal[0] != '\'' || literal[2] != '\'')
		return (false);
	if (!isascii(literal[1]))
		return (false);
	return (true);
}

static bool isInt(std::string literal)
{
	std::string::const_iterator it = literal.begin();
	while (it != literal.end() && std::isdigit(*it))
		it++;
	return (it == literal.end());
}

static t_type detectType(std::string literal)
{
	if (isChar(literal))
		return (CHAR);
	if (isInt(literal))
		return (INT);
	return (NONE);
}

void ScalarConverter::convert(std::string literal)
{
	if (literal.empty())
		return;
	// TODO: detect the type
	t_type type = detectType(literal);
	std::cout << type;
	// TODO: convert to the type
	// TODO: explicit conversion to other types, if overflow or impossible display error
	// TODO: display result

	(void)type;
	(void)literal;
}
