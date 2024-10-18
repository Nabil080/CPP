#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class	ICharacter;

class	AMateria
{
	protected:
		std::string	type;

	public: // constructors
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria();

		AMateria	&operator=(const AMateria &other);
	public: // methods
		std::string const & getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target) = 0;
};

#endif
