#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include "Brain.hpp"

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal&);
		virtual ~Animal();

		Animal	&operator=(const Animal&);

	public:
		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif
