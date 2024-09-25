#include "HumanB.hpp"
#include <iostream>

void    HumanB::attack(void)
{
    if (this->weapon)
        std::cout << this->name << " attacks with \033[34m" << this->weapon->getType() << "\033[0m" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}