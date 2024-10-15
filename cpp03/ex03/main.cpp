#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	diamondtrap("Edmond");
	DiamondTrap	diamondtrap2;

	diamondtrap.whoAmI();
	diamondtrap.attack("test");
	diamondtrap2.whoAmI();
}
