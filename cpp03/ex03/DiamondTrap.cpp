
#include "DiamondTrap.hpp"
#include <iostream>

// constructors 

DiamondTrap::DiamondTrap()
{
	if (debug)
		std::cout << "[ClapTrap Default constructor called]" << std::endl;
	this->name = "unnamed";
	this->ClapTrap::name = "unnamed_clap_name";
	this->ClapTrap::hitPoints = this->FragTrap::baseHitPoints;
	this->ClapTrap::energyPoints = this->ScavTrap::baseEnergyPoints;
	this->ClapTrap::attackDamage = this->FragTrap::baseAttackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name)
{
	if (debug)
		std::cout << "[DiamondTrap Default Constructor called]" << std::endl;
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	this->ClapTrap::hitPoints = this->FragTrap::baseHitPoints;
	this->ClapTrap::energyPoints = this->ScavTrap::baseEnergyPoints;
	this->ClapTrap::attackDamage = this->FragTrap::baseAttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	if (debug)
		std::cout << "[DiamondTrap Copy Constructor called]" << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	if (debug)
		std::cout << "[DiamondTrap Destructor called]" << std::endl;
}

// operators

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (debug)
		std::cout << "[DiamondTrap Assignation operator called]" << std::endl;
	this->name = other.name;
	this->ClapTrap::name = other.ClapTrap::name;
	this->ClapTrap::hitPoints = other.ClapTrap::hitPoints;
	this->ClapTrap::energyPoints = other.ClapTrap::energyPoints;
	this->ClapTrap::attackDamage = other.ClapTrap::attackDamage;
	return (*this);
}

// methods

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->name << ". " << this->ClapTrap::name << " is my old name." << std::endl;
	std::cout << "I have " << this->hitPoints << " hitPoints" << std::endl; 
	std::cout << "I have " << this->energyPoints << " energyPoints" << std::endl; 
	std::cout << "I have " << this->attackDamage << " attackDamage" << std::endl; 

}

void	DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}
