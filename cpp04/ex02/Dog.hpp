#ifndef DOG_HPP
# define DOG_HPP

# include "A_Animal.hpp"
# include "Brain.hpp"

class	Dog: public A_Animal
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
