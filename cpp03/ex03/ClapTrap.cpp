#include "ClapTrap.hpp"
#include <iostream>

// Constructor

ClapTrap::ClapTrap() : name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	if (debug)
		std::cout << "[ClapTrap Default constructor called]" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	if (debug)
		std::cout << "[ClapTrap Name constructor called]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	if (debug)
		std::cout << "[ClapTrap Copy constructor called]" << std::endl;
}

ClapTrap::~ClapTrap()
{
	if (debug)
		std::cout << "[ClapTrap Destructor called]" << std::endl;
}

// Operator

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (debug)
		std::cout << "[ClapTrap Assignation operator called]" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return (*this);
}

// Member function

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << name << " is dead and can't attack!" << std::endl;
	else if (this->energyPoints < 1)
		std::cout << "ClapTrap " << name << " has no energy left to attack!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " took " << amount << " points of damage!" << std::endl;
	this->hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << name << " is dead and can't be repaired!" << std::endl;
	else if (this->energyPoints < 1)
		std::cout << "ClapTrap " << name << " has no energy left to be repaired!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " has been repaired by " << amount << " points!" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
	}
}

// Getters

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}

