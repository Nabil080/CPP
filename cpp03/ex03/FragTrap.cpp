#include "FragTrap.hpp"
#include <iostream>

// Constructor

FragTrap::FragTrap()
{
	if (debug)
		std::cout << "[FragTrap Default Constructor called]" << std::endl;
	this->name = "FragTrap";
	this->hitPoints = this->baseHitPoints;
	this->energyPoints = this->baseEnergyPoints;
	this->attackDamage = this->baseAttackDamage;
}

FragTrap::FragTrap(const std::string &name)
{
	if (debug)
		std::cout << "[FragTrap Default Constructor called]" << std::endl;
	this->name = name;
	this->hitPoints = this->baseHitPoints;
	this->energyPoints = this->baseEnergyPoints;
	this->attackDamage = this->baseAttackDamage;
}

FragTrap::FragTrap(const FragTrap &other)
{
	if (debug)
		std::cout << "[FragTrap Copy Constructor called]" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	if (debug)
		std::cout << "[FragTrap Destructor called]" << std::endl;
}

// Operator

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (debug)
		std::cout << "[FragTrap Assignation operator called]" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->name << " is requesting a high five!" << std::endl;
}
