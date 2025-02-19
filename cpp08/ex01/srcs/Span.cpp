#include "Span.hpp"

#include <algorithm>
#include <climits>
#include <iostream>
#include <stdexcept>

// constructors

Span::Span() : _capacity(10)
{
	std::cerr << "[Span default constructor]" << std::endl;
}

Span::Span(unsigned int capacity) : _capacity(capacity)
{
	std::cerr << "[Span capacity constructor]" << std::endl;
	_values.reserve(capacity);
}

Span::Span(const Span &other) : _capacity(other._capacity)
{
	std::cerr << "[Span copy constructor]" << std::endl;
}

Span::~Span()
{
	std::cerr << "[Span destructor]" << std::endl;
}

// operators

Span &Span::operator=(const Span &other)
{
	_capacity = other._capacity;
	_values.resize(other._capacity);
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Span &obj)
{
	out << "[Span Infos]" << std::endl;
	out << "Values :";
	for (std::vector<int>::const_iterator it = obj.getValues().begin(); it != obj.getValues().end(); it++)
		out << " " << *it;
	out << std::endl;
	out << "capacity : " << obj.getCapacity() << std::endl;
	out << "Size : " << obj.getValues().size() << std::endl;
	try
	{
		obj.shortestSpan();
		out << "Shortest span : " << obj.shortestSpan() << std::endl;
	}
	catch (std::length_error &e)
	{
		out << "Shortest span : None " << std::endl;
	}
	try
	{
		obj.longestSpan();
		out << "Longest span : " << obj.longestSpan() << std::endl;
	}
	catch (std::length_error &e)
	{
		out << "Longest span : None " << std::endl;
	}
	return (out);
}

// getters

unsigned int Span::getCapacity() const
{
	return (_capacity);
}

const std::vector<int> &Span::getValues() const
{
	return (_values);
}

// methods

void Span::addNumber(int number)
{
	if (_values.size() == _capacity)
		throw std::length_error("Span is at max capacity");
	_values.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_values.size() < 2)
		throw std::length_error("There are less than 2 values inside Span");
	int              diff = INT_MAX;
	std::vector<int> copy = _values;

	std::sort(copy.begin(), copy.end());
	for (std::vector<int>::iterator it = copy.begin(); it + 1 != copy.end(); it++)
		if (diff > *(it + 1) - *it)
			diff = *(it + 1) - *it;
	return (diff);
}

unsigned int Span::longestSpan() const
{
	if (_values.size() < 2)
		throw std::length_error("There are less than 2 values inside Span");
	int max = *(std::max_element(_values.begin(), _values.end()));
	int min = *(std::min_element(_values.begin(), _values.end()));
	return (max - min);
}
