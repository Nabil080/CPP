#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
    private:
        Weapon*     weapon;
        std::string name;
    public:
        HumanB(std::string name): weapon(NULL), name(name) {};
        void    setWeapon(Weapon &weapon);
        void    attack(void);
};

#endif