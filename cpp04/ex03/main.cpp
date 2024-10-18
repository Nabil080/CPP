#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

#include <iostream>

void	sep(std::string str = "", bool nl = false)
{
	std::cout << std::endl << "-------" << str << "-------" << std::endl;
	if (nl)
		std::cout << std::endl;
}

void	subject_test()
{
	sep("Subject Test", true);
	IMateriaSource* src = new MateriaSource();

	AMateria* tmp = new Ice();
	src->learnMateria(tmp);
	delete tmp;
	tmp = new Cure();
	src->learnMateria(tmp);
	delete tmp;

	ICharacter* me = new Character("me");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete	tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete	tmp;

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	materia_test()
{
	sep("Materia Test", true);
	AMateria*	ice = new Ice();
	std::cout << "ice: " + ice->getType() << std::endl;
	AMateria* 	cure = new Cure();
	std::cout << "cure: " + cure->getType() << std::endl;

	AMateria*	test = ice->clone();	// clone
	std::cout << "clone: " + test->getType() << std::endl;
	*test = *cure;						// assignement operator
	std::cout << "assignement: " + test->getType() << std::endl;

	ICharacter* dummy = new Character("dummy");
	ice->use(*dummy);
	cure->use(*dummy);
	test->use(*dummy);
	delete dummy;

	delete ice;
	delete cure;
	delete test;
}

void	materia_source_test()
{
	sep("Materia Source Test", true);
	IMateriaSource* source = new MateriaSource();
	AMateria*		result = source->createMateria("ice");
	std::cout << (result ? "Success" : "Failure") << std::endl;

	AMateria* ice = new Ice();
	source->learnMateria(ice);
	result = source->createMateria("ice");
	std::cout << (result ? "Success" : "Failure") << std::endl;
	delete result;

	AMateria* cure = new Cure();
	source->learnMateria(cure);
	result = source->createMateria("cure");
	std::cout << (result ? "Success" : "Failure") << std::endl;
	delete result;

	source->learnMateria(ice);
	source->learnMateria(ice);
	source->learnMateria(ice);
	source->learnMateria(ice);
	source->learnMateria(ice);
	source->learnMateria(ice);

	IMateriaSource* copy = source;
	result = copy->createMateria("cure");
	std::cout << (result ? "Success" : "Failure") << std::endl;
	delete result;

	source->cleanMaterias();
	std::cout << (source->createMateria("ice") ? "Success" : "Failure") << std::endl;

	delete ice; delete cure;
	delete source;
}

void	character_test()
{
	sep("Character Test", true);
	ICharacter*	bob = new Character("bob");
	std::cout << "My name is " << bob->getName() << std::endl;

	AMateria*	ice = new Ice();
	AMateria*	cure = new Cure();

	bob->equip(ice);
	bob->use(0, *bob);
	sep("Testing for wrong inventory index");
	bob->use(1, *bob);
	AMateria*	tmp = bob->unequip(0);
	if (tmp)
		delete tmp;
	bob->unequip(1);
	sep("Testing for full inventory");
	bob->equip(cure);
	bob->equip(cure);
	bob->equip(cure);
	bob->equip(cure);
	bob->equip(cure);

	sep("Testing for deep copy");
	Character	original("original");
	original.equip(cure);
	Character	copy(original);
	original.cleanInventory();
	original.use(0, *bob);
	copy.use(0, *bob);

	copy.cleanInventory();

	delete ice; delete cure;
	delete bob;
}

int main()
{
	subject_test();
	materia_test();
	materia_source_test();
	character_test();
}
