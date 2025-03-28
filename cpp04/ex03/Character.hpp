#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	ICharacter;
class	AMateria;

# include <string>

class	Character: public ICharacter
{
	private:
		std::string				name;
		static const size_t		max_size = 4;
		AMateria				*materias[max_size + 1]; // inventory

	public: // constructors
		Character();
		Character(const std::string &name);
		Character(const Character&);
		~Character();

		Character	&operator=(const Character&);

	public: // methods
		std::string const			&getName() const;

		void				equip(AMateria *materia);
		AMateria			*unequip(int index);
		void				use(int index, ICharacter &target);
		void				cleanInventory();
};

#endif
