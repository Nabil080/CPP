#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat&);
		~WrongCat();

		WrongCat	&operator=(const WrongCat&);

		void	makeSound() const;
};

#endif
