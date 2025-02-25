#include "RPN_TEST.hpp"

#include <iostream>

// constructors

RPN_Test::RPN_Test()
{
	std::cerr << "[RPN_Test default constructor]" << std::endl;
}

RPN_Test::RPN_Test(std::string expression, std::string expected_error)
	: _input(expression), _expected_error(expected_error), _expected_result(0), _result(0)
{
	std::cerr << "[RPN_Test expected_error constructor]" << std::endl;
}

RPN_Test::RPN_Test(std::string expression, int expected_result)
	: _input(expression), _expected_result(expected_result), _result(0)
{
	std::cerr << "[RPN_Test expected_result constructor]" << std::endl;
}

RPN_Test::RPN_Test(const RPN_Test &other)
	: _input(other._input), _expected_error(other._expected_error), _expected_result(other._expected_result),
	  _error(other._error), _result(other._result), _passed(other._passed)
{
	std::cerr << "[RPN_Test copy constructor]" << std::endl;
}

RPN_Test::~RPN_Test()
{
	std::cerr << "[RPN_Test destructor]" << std::endl;
}

// operators

RPN_Test &RPN_Test::operator=(const RPN_Test &other)
{
	if (this == &other)
		return (*this);
	_expression = other._expression;
	_expected_result = other._expected_result;
	_expected_error = other._expected_error;
	return (*this);
}

// methods

void RPN_Test::setPassed()
{

	try
	{
		::RPN::setExpression(_input);
	}
	catch (std::runtime_error &e)
	{
		_error = e.what();
	}

	if (_error.empty() == false) // problem setting the expression
	{
		if (_error == _expected_error)
			_passed = true;
		else
			_passed = false;
	}
	else
	{
		_result = ::RPN::getResult();
		if (_result == _expected_result)
			_passed = true;
		else
			_passed = false;
	}
}

void RPN_Test::printTest()
{
	setPassed();

	std::cout << "--------------------------------" << std::endl << std::endl;
	std::cout << "TESTING :" << _input << std::endl;
	if (_expected_error.empty() == false)
		std::cout << "Expected error :" << _expected_error << std::endl;
	else
		std::cout << "Expected result :" << _expected_result << std::endl;
	if (_error.empty() == false)
		std::cout << "Got error :" << _error << std::endl;
	else
		std::cout << "Got result :" << _result << std::endl;
	std::cout << (_passed ? "[PASSED]" : "[FAILED]");
	std::cout << std::endl << std::endl;
}
