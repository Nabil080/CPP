#include "Cat.hpp"

#include <iostream>

// canon

Cat::Cat()
{
	std::cout << "[Cat default constructor]" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other)
{
	std::cout << "[Cat copy constructor]" << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout << "[Cat destructor]" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "[Cat copy operator]" << std::endl;
	this->type = other.type;
	return (*this);
}

// methods

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
