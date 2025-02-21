#include "RPN.hpp"

#include <iostream>

const std::string RPN::_tokens = "+-/*";
const std::string RPN::_base = "0124356789";

// constructors

RPN::RPN()
{
	std::cerr << "[RPN default constructor]" << std::endl;
}

RPN::RPN(std::string expression) : _expr_stack(setExpr(expression))
{
	std::cerr << "[RPN expression constructor]" << std::endl;
}

RPN::RPN(const RPN &other) : _expr_stack(other._expr_stack), _result_stack(other._result_stack)
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
	_expr_stack = other._expr_stack;
	_result_stack = other._result_stack;
	return (*this);
}

// methods

std::stack<char> RPN::setExpr(std::string expression)
{
	std::string::iterator it = expression.begin();
	size_t                token_count = 0;
	size_t                nbr_count = 0;

	while (it != expression.end())
	{
		while (*it == ' ')
			it++;

		if (_tokens.find(*it) != std::string::npos)
		{
			_expr_stack.push(*it);
			token_count++;
		}
		else if (_base.find(*it) != std::string::npos)
		{
			_expr_stack.push(*it);
			nbr_count++;
		}
		else if (it == expression.end())
			break;
		else
			throw(std::runtime_error("Invalid character inside the expression"));
		it++;
		if (it != expression.end() && *it != ' ')
			throw(std::runtime_error("Invalid character inside the expression"));
	}
	if (token_count != nbr_count - 1)
		throw(std::runtime_error("Invalid expression"));

	return (_expr_stack);
}
