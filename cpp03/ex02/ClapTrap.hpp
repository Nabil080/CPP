#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#	include <string>

class	ClapTrap
{
	protected:
		static const int	debug = 1;
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;
	
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap&	operator=(const ClapTrap& other);

	public:
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	public:
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
};

#endif
