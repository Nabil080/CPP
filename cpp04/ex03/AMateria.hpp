#ifndef AMATERIA
# define AMATERIA

# include <string>

# include "ICharacter.hpp"

class	AMateria
{
	protected:
		std::string	type;

	public: // constructors
		AMateria();
		AMateria(std::string const & type);
		virtual	~AMateria() = 0;


	public: // methods
		std::string const & getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
