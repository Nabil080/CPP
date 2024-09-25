#include "HumanA.hpp"
#include <iostream>

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with \033[34m" << this->weapon.getType() << "\033[0m" << std::endl;
}