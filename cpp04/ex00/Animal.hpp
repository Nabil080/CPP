#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal&);
		~Animal();

		Animal	&operator=(const Animal&);

		std::string	getType() const;
		virtual void	makeSound() const;
};

#endif
