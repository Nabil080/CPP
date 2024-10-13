#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	claptrap("ClaptTrap");
	ScavTrap	scavtrap("ScavTrap");

	claptrap.attack("ScavTrap");
	scavtrap.takeDamage(5);
	scavtrap.attack("ClapTrap");
	claptrap.takeDamage(5);
	scavtrap.guardGate();
	claptrap.attack("ScavTrap");
	scavtrap.takeDamage(5);
	scavtrap.attack("ClapTrap");
	claptrap.beRepaired(5);
}
