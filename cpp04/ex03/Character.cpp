#include "Character.hpp"
#include "AMateria.hpp"

#include <iostream>
#include <string>

// constructors

Character::Character()
{
	std::cerr << "[Character Default Constructor called]" << std::endl;
	this->name = "undefined";
	for (size_t i = 0; i < this->max_size; i++)
		this->materias[i] = NULL;
}

Character::Character(const std::string &name)
{
	std::cerr << "[Character Name Constructor called]" << std::endl;
	this->name = name;
	for (size_t i = 0; i < this->max_size; i++)
		this->materias[i] = NULL;
}

Character::Character(const Character &other)
{
	std::cerr << "[Character Copy Constructor called]" << std::endl;
	*this = other;
}

Character::~Character()
{
	std::cerr << "[Character Destructor called]" << std::endl;
	for (size_t i = 0; i < this->max_size; i++)
		if (this->materias[i])
			delete this->materias[i];
}

Character	&Character::operator=(const Character &other)
{
	std::cerr << "[Character assignement operator called]" << std::endl;
	this->name = other.name;
	for (size_t i = 0; i < this->max_size; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
		if (other.materias[i])
			this->materias[i] = other.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
}

// methods

std::string const	&Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria *materia)
{
	size_t	i = 0;

	while(this->materias[i] && i < this->max_size)
		i++;
	if (i < this->max_size)
		this->materias[i] = materia;
}

void	Character::unequip(int index)
{
	this->materias[index] = NULL;
}

void	Character::use(int index, ICharacter &target)
{
	if (this->materias[index] == NULL)
		return ;
	this->materias[index]->use(target);
}
