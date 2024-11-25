#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal
{
	public:
		std::string	type;

	public:
		Animal();
		Animal(const Animal&);
		virtual ~Animal();

		Animal	&operator=(const Animal&);

		std::string	getType() const;
		virtual void	makeSound() const;
};

#endif
