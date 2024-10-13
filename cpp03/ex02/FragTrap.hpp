#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
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
