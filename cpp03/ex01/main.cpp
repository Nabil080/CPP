#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	claptrap("-Clap-");
	ScavTrap	scavtrap("-Scav-");

	claptrap.attack("-Scav-");
	scavtrap.takeDamage(5);
	scavtrap.attack("-Clap-");
	claptrap.takeDamage(5);
	scavtrap.guardGate();
	claptrap.attack("-Scav-");
	scavtrap.takeDamage(5);
	scavtrap.attack("-Clap-");
	claptrap.beRepaired(5);
}
