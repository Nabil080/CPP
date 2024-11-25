#include "Zombie.hpp"
# include <iostream>

Zombie::Zombie(void)
{
    std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << name << " is being destroyed" << std::endl;
}

void    Zombie::setName(std::string name)
{
	std::cout << "name setter called for " << name << std::endl;
    this->name = name;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}