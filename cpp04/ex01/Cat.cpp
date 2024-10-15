#include "Cat.hpp"
#include <iostream>

// canon

Cat::Cat()
{
	std::cerr << "[Cat default constructor]" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
	this->brain->ideas[0] = "Cat brain";
}

Cat::Cat(const Cat &other)
{
	std::cerr << "[Cat copy constructor]" << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cerr << "[Cat destructor]" << std::endl;
	delete this->brain;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cerr << "[Cat copy operator]" << std::endl;
	this->type = other.type;
	return (*this);
}

// methods

void	Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
