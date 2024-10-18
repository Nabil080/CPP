#include "Ice.hpp"
#include "ICharacter.hpp"

#include <iostream>

// constructors

Ice::Ice()
{
	std::cerr << "[Ice Default Constructor called]" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice &other)
{
	std::cerr << "[Ice Copy Constructor called]" << std::endl;
	*this = other;
}

Ice::~Ice()
{
	std::cerr << "[Ice Destructor called]" << std::endl;
}
Ice	&Ice::operator=(const Ice &other)
{
	std::cerr << "[Ice Assignement Operator called]" << std::endl;
	if (other.type == "ice")
		*this = other;
	return (*this);
}

// methods

void	Ice::use(ICharacter &character)
{
	std::cout << "* shoots an ice bolt at " + character.getName() + " *" << std::endl;
}

AMateria*	Ice::clone() const
{
	return (new Ice());
}
