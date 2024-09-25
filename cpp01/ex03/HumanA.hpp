#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA
{
    private:
        Weapon&     weapon;
        std::string name;
    public:
        HumanA(std::string name, Weapon& weapon): weapon(weapon), name(name) {};
        void    attack(void);
};

#endif