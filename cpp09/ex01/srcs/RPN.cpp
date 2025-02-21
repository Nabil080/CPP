#include "RPN.hpp"

#include <cstdlib>
#include <iostream>

const std::string RPN::_tokens = "+-/*";
const std::string RPN::_base = "0124356789";

// constructors

RPN::RPN()
{
	std::cerr << "[RPN default constructor]" << std::endl;
}

RPN::RPN(std::string expression) : _expression(setExpression(expression))
{
	std::cerr << "[RPN expression constructor]" << std::endl;
}

RPN::RPN(const RPN &other) : _expression(other._expression)
{
	std::cerr << "[RPN copy constructor]" << std::endl;
}

RPN::~RPN()
{
	std::cerr << "[RPN destructor]" << std::endl;
}

// operators

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
		return (*this);
	_expression = other._expression;
	return (*this);
}

// methods

std::string RPN::setExpression(std::string expression)
{
	std::string::iterator it = expression.begin();
	bool                  parsing_tokens = false;
	int                   tokens_needed = -1;

	while (it != expression.end())
	{
		while (*it == ' ')
			it++;

		if (_tokens.find(*it) != std::string::npos)
		{
			if (tokens_needed < 1)
				throw(std::runtime_error("Too much operators after a number"));
			parsing_tokens = true;
			_expression.push_back(*it);
			tokens_needed--;
			if (tokens_needed == 0)
				parsing_tokens = false;
		}
		else if (_base.find(*it) != std::string::npos)
		{
			if (parsing_tokens == true)
				throw(std::runtime_error("Not enough operators after a number"));
			_expression.push_back(*it);
			tokens_needed++;
		}
		else if (it == expression.end())
			break;
		else
			throw(std::runtime_error("Invalid character inside the expression"));
		it++;
		if (it != expression.end() && *it != ' ')
			throw(std::runtime_error("Invalid character inside the expression"));
	}
	if (tokens_needed != 0)
		throw(std::runtime_error("Not enough operators after a number"));

	return (_expression);
}

int RPN::getResult()
{
	std::stack<int>       result;
	std::string::iterator it;
	int                   nb1;
	int                   nb2;

	for (it = _expression.begin(); it != _expression.end(); it++)
	{
		if (_base.find(*it) != std::string::npos)
			result.push(*it - '0');
		else if (_tokens.find(*it) != std::string::npos)
		{
			nb1 = result.top();
			result.pop();
			nb2 = result.top();
			result.pop();
			if (*it == '+')
				result.push(nb2 + nb1);
			if (*it == '-')
				result.push(nb2 - nb1);
			if (*it == '/')
				result.push(nb2 / nb1);
			if (*it == '*')
				result.push(nb2 * nb1);
			// std::cout << std::endl
			// 		  << "Calculated " << nb2 << " " << *it << " " << nb1 << " = " << result.top() << std::endl;
		}
		// std::cout << result.top() << " ";
	}
	// std::cout << std::endl;

	return (result.top());
}
