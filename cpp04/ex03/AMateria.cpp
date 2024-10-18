#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>
#include <string>

// constructors

AMateria::AMateria()
{
	std::cerr << "[AMateria Default Constructor called]" << std::endl;
	this->type = "none";
}

AMateria::AMateria(std::string const & type)
{
	std::cerr << "[AMateria Type Constructor called]" << std::endl;
	this->type = type;
}

AMateria::~AMateria()
{
	std::cerr << "[AMateria Destructor called]" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	std::cerr << "[AMateria Assignement Operator called]" << std::endl;
	this->type = other.type;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (this->type);
}
