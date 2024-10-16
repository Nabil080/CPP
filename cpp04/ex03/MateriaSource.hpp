#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class	MateriaSource: public IMateriaSource
{
	private:
		static const size_t		max_size = 4;
		AMateria				*materias[max_size];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource&);
		~MateriaSource();

		MateriaSource	&operator=(const MateriaSource&);

	public:
		void 		learnMateria(AMateria*);
		AMateria* 	createMateria(std::string const & type);
};

#endif
