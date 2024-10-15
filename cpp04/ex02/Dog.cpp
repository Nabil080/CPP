#include "Dog.hpp"
#include <iostream>

// canon

Dog::Dog()
{
	std::cerr << "[Dog default constructor]" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	this->brain->ideas[0] = "Dog brain";
}

Dog::Dog(const Dog &other)
{
	std::cerr << "[Dog copy constructor]" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cerr << "[Dog destructor]" << std::endl;
	delete this->brain;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cerr << "[Dog copy operator]" << std::endl;
	this->type = other.type;
	return (*this);
}

// methods

void	Dog::makeSound() const
{
	std::cout << "Bark bark" << std::endl;
}
