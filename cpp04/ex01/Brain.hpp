#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const Brain&);
		~Brain();
		Brain	&operator=(const Brain&);

	public:
		std::string getIdea(size_t index) const;
		void		setIdea(size_t index, std::string idea);
};

#endif
