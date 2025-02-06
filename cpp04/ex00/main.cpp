#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

void testSound(const WrongAnimal *animal)
{
	std::cout << animal->getType() << " -> ", animal->makeSound();
}

void testSound(const Animal *animal)
{
	std::cout << animal->getType() << " -> ", animal->makeSound();
}

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	// will output the cat sound!
	testSound(i);
	testSound(j);
	testSound(meta);

	delete meta;
	delete i;
	delete j;
	std::cout << "----------------------------------" << std::endl;

	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	// will output the animal sound!
	testSound(wrongAnimal);
	// will output the animal sound!
	testSound(wrongCat);

	delete wrongAnimal;
	delete wrongCat;
	return 0;
}
