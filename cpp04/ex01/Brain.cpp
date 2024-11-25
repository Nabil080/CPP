#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cerr << "[Brain default constructor]" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = "Empty idea";
}

Brain::Brain(const Brain &other)
{
	std::cerr << "[Brain copy constructor]" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cerr << "[Brain default destructor]" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cerr << "[Brain copy operator]" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}
