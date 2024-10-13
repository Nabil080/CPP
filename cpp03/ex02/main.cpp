#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap	fragtrap("FragTrap");
	ScavTrap	scavtrap("ScavTrap");

	fragtrap.attack("ScavTrap");
	scavtrap.takeDamage(5);
	scavtrap.attack("FragTrap");
	fragtrap.takeDamage(5);
	scavtrap.guardGate();
	fragtrap.attack("ScavTrap");
	scavtrap.takeDamage(5);
	scavtrap.attack("FragTrap");
	fragtrap.beRepaired(5);
	fragtrap.highFivesGuys();
}
