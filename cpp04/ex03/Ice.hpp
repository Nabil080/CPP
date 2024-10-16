#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice&);
		~Ice();

		Ice	&operator=(const Ice&);

	public:
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
