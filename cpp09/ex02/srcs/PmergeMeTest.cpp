#include "PmergeMeTest.hpp"

#include <algorithm>
#include <iostream>

// constructors

PmergeMeTest::PmergeMeTest()
{
	std::cerr << "[PmergeMeTest default constructor]" << std::endl;
}

PmergeMeTest::PmergeMeTest(std::string sequence, std::string expected) : PmergeMe(sequence)
{
	if (expected.empty() == false && std::isalpha(expected[0]))
	{
		std::cerr << "[PmergeMeTest expected_error constructor]" << std::endl;
		_expected_error = expected;
	}
	else
	{
		std::cerr << "[PmergeMeTest expected_result constructor]" << std::endl;
		_expected_result = expected;
	}
}

PmergeMeTest::PmergeMeTest(std::vector<int> numbers) : PmergeMe(containerToString(numbers))
{
	std::sort(numbers.begin(), numbers.end());
	_expected_result = containerToString(numbers);
}

PmergeMeTest::PmergeMeTest(const PmergeMeTest &other)
	: PmergeMe(other), _error(other._error), _result(other._result), _expected_error(other._expected_error), _expected_result(other._expected_result)
{
	std::cerr << "[PmergeMeTest copy constructor]" << std::endl;
}

PmergeMeTest::~PmergeMeTest()
{
	std::cerr << "[PmergeMeTest destructor]" << std::endl;
}

// operators

PmergeMeTest &PmergeMeTest::operator=(const PmergeMeTest &other)
{
	if (this == &other)
		return (*this);
	_sequence = other._sequence;
	_error = other._error;
	_result = other._result;
	_expected_result = other._expected_result;
	_expected_error = other._expected_error;
	_passed = other._passed;
	return (*this);
}

// methods

void PmergeMeTest::setPassed()
{
	try
	{
		PmergeMe::parseSequence();
	}
	catch (std::runtime_error &e)
	{
		_error = e.what();
	}

	if (_error.empty() == false) // parsing error
	{
		if (_error == _expected_error)
			_passed = true;
		else
			_passed = false;
	}
	else
	{
		try
		{
			PmergeMe::sortVector();
			PmergeMe::sortList();
		}
		catch (std::bad_alloc &e)
		{
			_error = e.what();
			return;
		}
		_result = containerToString(PmergeMe::_vector_data.sequence);
		if (_result != _expected_result || _result != containerToString(PmergeMe::_list_data.sequence))
			_passed = false;
		else
			_passed = true;
	}
}

void PmergeMeTest::printTest()
{
	setPassed();

	std::cout << "--------------------------------" << std::endl << std::endl;
	std::cout << "TESTING :" << ::PmergeMe::_sequence << std::endl;
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
