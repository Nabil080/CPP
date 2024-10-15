#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string			name;
		static const int	debug = 0;

	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap&);
		~DiamondTrap();

		DiamondTrap&	operator=(const DiamondTrap&);

	public:
		void	attack(const std::string& target);
		void	whoAmI();
};

#endif
