#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap
{
	protected:
		static const int baseHitPoints = 100;
		static const int baseEnergyPoints = 50;
		static const int baseAttackDamage = 20;

	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		~ScavTrap();
		ScavTrap(const ScavTrap& other);
	
		ScavTrap&	operator=(const ScavTrap& other);
	public:
		void	attack(const std::string& target);
		void	guardGate(void) const;
};

#endif
