#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain
{
	public:
		Brain();
		Brain(const Brain&);
		~Brain();
		Brain	&operator=(const Brain&);

	public:
		std::string	ideas[100];
};

#endif
