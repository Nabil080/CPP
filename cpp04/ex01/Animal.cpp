#include "Animal.hpp"
#include <iostream>

// canon

Animal::Animal()
{
	std::cerr << "[Animal default constructor]" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &other)
{
	std::cerr << "[Animal copy constructor]" << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cerr << "[Animal destructor]" << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	std::cerr << "[Animal copy operator]" << std::endl;
	this->type = other.type;
	return (*this);
}

// methods

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Random animal sound" << std::endl;
}
