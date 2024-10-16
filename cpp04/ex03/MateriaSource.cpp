#include "MateriaSource.hpp"
#include "AMateria.hpp"

#include <iostream>

// constructors

MateriaSource::MateriaSource()
{
	std::cerr << "[MateriaSource Default Constructor called]" << std::endl;
	for (size_t i = 0; i < this->max_size; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cerr << "[MateriaSource Copy Constructor called]" << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource()
{
	std::cerr << "[MateriaSource Destructor called]" << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cerr << "[MateriaSource Assignement Operator called]" << std::endl;
	for (size_t i = 0; i < this->max_size; i++)
		this->materias[i] = other.materias[i];
	return (*this);
}

// methods

void MateriaSource::learnMateria(AMateria* Amateria)
{
	size_t	i = 0;

	while(this->materias[i] && i < this->max_size)
		i++;
	if (i < this->max_size)
		this->materias[i] = Amateria;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	size_t	i = 0;

	while(this->materias[i] && i < this->max_size)
	{
		if (type == this->materias[i]->getType())
			return (this->materias[i]->clone());
		i++;
	}
	return (0);
}

void	MateriaSource::cleanMaterias()
{
	for (size_t i = 0; i < this->max_size; i++)
		if (this->materias[i])
			delete this->materias[i];
}
