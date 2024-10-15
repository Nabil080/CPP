#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal
{
	public:
		Brain	*brain;
	public:
		Dog();
		Dog(const Dog&);
		~Dog();
		Dog	&operator=(const Dog&);

	public:
		void	makeSound() const;
};

#endif
