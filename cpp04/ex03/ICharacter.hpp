#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

class	AMateria;

class	ICharacter
{
	public:
		// ICharacter() {};
		// ICharacter(const ICharacter &) {};
		// void operator=(const ICharacter &) {};
		virtual	~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void 		equip(AMateria* m) = 0;
		virtual AMateria	*unequip(int idx) = 0;
		virtual void 		use(int idx, ICharacter& target) = 0;
		virtual void 		cleanInventory() = 0;

};

#endif
