#include "WrongAnimal.hpp"
#include <iostream>

// canon

WrongAnimal::WrongAnimal()
{
	std::cerr << "[WrongAnimal default constructor]" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cerr << "[WrongAnimal copy constructor]" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cerr << "[WrongAnimal destructor]" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cerr << "[WrongAnimal copy operator]" << std::endl;
	this->type = other.type;
	return (*this);
}

// methods

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Random WrongAnimal sound" << std::endl;
}
