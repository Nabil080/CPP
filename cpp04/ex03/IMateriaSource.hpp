#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class	AMateria;

class IMateriaSource
{
	public:
		IMateriaSource() {};
		IMateriaSource(const IMateriaSource&) {};
		void	operator=(const IMateriaSource&) {};
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;

	public:
		virtual void	cleanMaterias() = 0;
};

#endif
