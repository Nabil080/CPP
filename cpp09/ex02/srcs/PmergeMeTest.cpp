#include "PmergeMeTest.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
// constructors

PmergeMeTest::PmergeMeTest()
{
	std::cerr << "[PmergeMeTest default constructor]" << std::endl;
}

PmergeMeTest::PmergeMeTest(std::string sequence, std::string expected) : _sequence(sequence)
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

PmergeMeTest::PmergeMeTest(std::string sequence) : _sequence(sequence) {}

PmergeMeTest::PmergeMeTest(std::vector<int> numbers) : _sequence(containerToString(numbers))
{
	std::sort(numbers.begin(), numbers.end());
	_expected_result = containerToString(numbers);
}

PmergeMeTest::PmergeMeTest(const PmergeMeTest &other)
	: PmergeMe(other), _error(other._error), _result(other._result), _expected_error(other._expected_error),
	  _expected_result(other._expected_result)
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

void PmergeMeTest::setError()
{
	try
	{
		PmergeMe::parseSequence<vector>(_sequence);
	}
	catch (std::runtime_error &e)
	{
		_error = e.what();
	}

	_passed = _error == _expected_error;
}

void PmergeMeTest::printTest()
{
	std::cout << "--------------------------------" << std::endl << std::endl;
	std::cout << "Before :" << _sequence << std::endl;
	setError();
	if (_expected_error != "") // check if error is matching expectations
	{
		std::cout << "After :" << _error << std::endl;
		std::cout << "Expected :" << _expected_error << std::endl;
	}
	else // check if sorted
	{
		clock_t start_vector = clock();
		vector	vec = PmergeMe::sortVector(_sequence);
		clock_t end_vector = clock();
		clock_t start_deque = clock();
		deque	deq = PmergeMe::sortDeque(_sequence);
		clock_t end_deque = clock();

		_result = containerToString(vec);
		std::sort(vec.begin(), vec.end());
		if (_expected_result == "")
			_expected_result = containerToString(vec);

		std::cout << "After :" << _result << std::endl;
		std::cout << "Expected :" << _expected_result << std::endl;
		std::cout << std::fixed << std::setprecision(6);
		std::cout << "Time to process a range of " << vec.size()
				  << " elements with std::vector: " << (double)(end_vector - start_vector) / CLOCKS_PER_SEC << "s"
				  << std::endl;
		std::cout << "Time to process a range of " << deq.size()
				  << " elements with std::deque: " << (double)(end_deque - start_deque) / CLOCKS_PER_SEC << "s"
				  << std::endl;

		_passed = _result == _expected_result && _result == containerToString(deq);
	}
	std::cout << (_passed ? GREEN + std::string("[PASSED]") : RED + std::string("[FAILED]"));
	std::cout << WHITE << std::endl << std::endl;
}
