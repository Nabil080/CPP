#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	claptrap1("ClapTrap1");
	ClapTrap	claptrap2("ClapTrap2");

	claptrap1.attack("ClapTrap2");
	claptrap2.takeDamage(5);
	claptrap2.attack("ClapTrap1");
	claptrap1.takeDamage(5);
	claptrap1.attack("ClapTrap2");
	claptrap2.takeDamage(5);
	claptrap2.attack("ClapTrap1");
	claptrap1.beRepaired(5);
}
