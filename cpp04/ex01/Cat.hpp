#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal
{
	public:
		Brain	*brain;
	public:
		Cat();
		Cat(const Cat&);
		~Cat();
		Cat	&operator=(const Cat&);

	public :
		void	makeSound() const;
};

#endif
