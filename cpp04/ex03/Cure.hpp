#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure&);
		~Cure();

		Cure &operator=(const Cure &);

	public:
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
