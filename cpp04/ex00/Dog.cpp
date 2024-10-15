#include "Dog.hpp"
#include <iostream>

// canon

Dog::Dog()
{
	std::cout << "[Dog default constructor]" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << "[Dog copy constructor]" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << "[Dog destructor]" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "[Dog copy operator]" << std::endl;
	this->type = other.type;
	return (*this);
}

// methods

void	Dog::makeSound() const
{
	std::cout << "Bark bark" << std::endl;
}
