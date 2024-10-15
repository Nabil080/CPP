#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>

class	WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal&);

		std::string	getType() const;
		void	makeSound() const;
};

#endif
