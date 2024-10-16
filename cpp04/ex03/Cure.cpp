#include "Cure.hpp"
#include "ICharacter.hpp"

#include <iostream>

// constructors

Cure::Cure()
{
	std::cerr << "[Cure Default Constructor called]" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure &other)
{
	std::cerr << "[Cure Copy Constructor called]" << std::endl;
	*this = other;
}

Cure::~Cure()
{
	std::cerr << "[Cure Destructor called]" << std::endl;
}

Cure	&Cure::operator=(const Cure &other)
{
	if (other.type == "cure")
		*this = other;
	return (*this);
}

// methods

void	Cure::use(ICharacter &character)
{
	std::cout << "* heals " + character.getName() + "'s wounds *" << std::endl;
}

AMateria*	Cure::clone() const
{
	return (new Cure());
}
