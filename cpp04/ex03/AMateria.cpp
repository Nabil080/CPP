#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>
#include <string>

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

std::string const	&AMateria::getType() const
{
	return (this->type);
}
