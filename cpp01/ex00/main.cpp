#include "Zombie.hpp"

Zombie* newZombie(std::string name);

void    randomChump(std::string name);

int main(void)
{
    Zombie *z1 = newZombie("Nabil");
    
    z1->announce();
    delete (z1);

    randomChump("Maxime");
    return (0);
}