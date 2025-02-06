#include "WrongCat.hpp"

#include <iostream>

// canon

WrongCat::WrongCat()
{
	std::cout << "[WrongCat default constructor]" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "[WrongCat copy constructor]" << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat destructor]" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "[WrongCat copy operator]" << std::endl;
	this->type = other.type;
	return (*this);
}

// methods

void WrongCat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
