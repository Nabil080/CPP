#include "Zombie.hpp"
# include <iostream>

Zombie::~Zombie(void)
{
    std::cout << name << " is being destroyed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}