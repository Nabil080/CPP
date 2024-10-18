#include "Character.hpp"
#include "AMateria.hpp"

#include <iostream>
#include <string>

// constructors

Character::Character()
{
	std::cerr << "[Character Default Constructor called]" << std::endl;
	this->name = "undefined";
	for (size_t i = 0; i < this->max_size + 1; i++)
		this->materias[i] = NULL;
}

Character::Character(const std::string &name)
{
	std::cerr << "[Character Name Constructor called]" << std::endl;
	this->name = name;
	for (size_t i = 0; i < this->max_size + 1; i++)
		this->materias[i] = NULL;
}

Character::Character(const Character &other)
{
	std::cerr << "[Character Copy Constructor called]" << std::endl;
	for (size_t i = 0; i < this->max_size + 1; i++)
		this->materias[i] = NULL;
	*this = other;
}

Character::~Character()
{
	std::cerr << "[Character Destructor called]" << std::endl;
	this->cleanInventory();
}

Character	&Character::operator=(const Character &other)
{
	std::cerr << "[Character assignement operator called]" << std::endl;
	this->name = other.getName();
	for (size_t i = 0; i < this->max_size; i++)
	{
		std::cout << this->materias[i] << std::endl;
		if (this->materias[i])
			delete this->materias[i];
		if (other.materias[i])
			this->materias[i] = other.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
	return (*this);
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
		this->materias[i] = materia->clone();
	else
		std::cout << "/!\\ " + this->name + "'s inventory is full !" << std::endl;
}

AMateria	*Character::unequip(int index)
{
	AMateria	*materia = this->materias[index];

	if (materia)
		std::cout << this->name + " unequipped " + this->materias[index]->getType() << std::endl;
	else
		std::cout << "/!\\ " + this->name + " has nothing equipped on slot " << index << std::endl;
	this->materias[index] = NULL;

	return (materia);
}

void	Character::use(int index, ICharacter &target)
{
	if (this->materias[index])
		this->materias[index]->use(target);
	else
		std::cout << "/!\\ " + this->name + " has nothing equipped on slot " << index << std::endl;
}

void	Character::cleanInventory()
{
	std::cerr << "[Clearing " + this->name + "'s inventory]" << std::endl;
	for (size_t i = 0; i < this->max_size; i++)
		if (this->materias[i])
		{
			delete this->materias[i];
			this->materias[i] = NULL;
		}
}