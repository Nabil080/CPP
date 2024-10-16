#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

#include <iostream>

void	subject_test()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	me->cleanInventory();
	delete me;
	src->cleanMaterias();
	delete src;
}

void	materia_test()
{
	AMateria*	ice = new Ice();
	AMateria*	clone = ice->clone();

	std::cout << "ice: " + ice->getType() << std::endl;
	std::cout << "clone: " + clone->getType() << std::endl;
}

int main()
{
	subject_test();
	// materia_test();
}
