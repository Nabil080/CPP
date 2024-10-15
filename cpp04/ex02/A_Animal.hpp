#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <string>
# include "Brain.hpp"

class	A_Animal
{
	protected:
		std::string	type;

	protected:
		A_Animal();
		A_Animal(const A_Animal&);
		virtual ~A_Animal();
		A_Animal	&operator=(const A_Animal&);

	public:
		std::string		getType() const;
		virtual void	makeSound() const = 0;
};

#endif
