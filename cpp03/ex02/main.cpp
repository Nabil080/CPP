#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap	fragtrap("-Frag-");
	ScavTrap	scavtrap("-Scav-");

	fragtrap.attack("-Scav-");
	scavtrap.takeDamage(5);
	scavtrap.attack("-Frag-");
	fragtrap.takeDamage(5);
	scavtrap.guardGate();
	fragtrap.attack("-Scav-");
	scavtrap.takeDamage(5);
	scavtrap.attack("-Frag-");
	fragtrap.beRepaired(5);
	fragtrap.highFivesGuys();
}
