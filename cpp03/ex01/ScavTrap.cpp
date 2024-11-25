#include "ScavTrap.hpp"
#include <iostream>

// Constructor

ScavTrap::ScavTrap()
{
	if (debug)
		std::cout << "[ScavTrap Default Constructor called]" << std::endl;
	this->name = "ScavTrap";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name)
{
	if (debug)
		std::cout << "[ScavTrap Name Constructor called]" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	if (debug)
		std::cout << "[ScavTrap Copy Constructor called]" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	if (debug)
		std::cout << "[ScavTrap Destructor called]" << std::endl;
}

// Operator

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (debug)
		std::cout << "[ScavTrap Assignation operator called]" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return (*this);
}


void	ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0)
		std::cout << "ScavTrap " << this->name << " is dead and can't attack!" << std::endl;
	else if (this->energyPoints < 1)
		std::cout << "ScavTrap " << this->name << " has no energy left to attack!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "Scavtrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}
