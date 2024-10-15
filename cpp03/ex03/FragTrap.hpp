#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap: virtual public ClapTrap
{
	protected:
		static const int	baseHitPoints = 100;
		static const int	baseEnergyPoints = 100;
		static const int	baseAttackDamage = 30;

	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(FragTrap const & copy);
		~FragTrap();
		FragTrap & operator=(FragTrap const & rhs);

	public:
		void	highFivesGuys(void) const;
};

#endif
