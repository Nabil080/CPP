#include "A_Animal.hpp"
#include <iostream>

// canon

A_Animal::A_Animal()
{
	std::cerr << "[A_Animal default constructor]" << std::endl;
	this->type = "A_Animal";
}

A_Animal::A_Animal(const A_Animal &other)
{
	std::cerr << "[A_Animal copy constructor]" << std::endl;
	*this = other;
}

A_Animal::~A_Animal()
{
	std::cerr << "[A_Animal destructor]" << std::endl;
}

A_Animal	&A_Animal::operator=(const A_Animal &other)
{
	std::cerr << "[A_Animal copy operator]" << std::endl;
	this->type = other.type;
	return (*this);
}

// methods

std::string	A_Animal::getType(void) const
{
	return (this->type);
}
