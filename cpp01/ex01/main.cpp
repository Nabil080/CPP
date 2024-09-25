#include "Zombie.hpp"

Zombie  *zombieHorde(size_t N, std::string name);

int main(void)
{
    size_t count = 10;
    Zombie *zombies = zombieHorde(count, "Maxime");

    for (size_t i = 0; i < count; i++)
        zombies[i].announce();
    delete[] zombies;
    return (0);
}
