#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	//will output the cat sound!
	std::cout << i->getType() << " -> ", i->makeSound();
	std::cout << j->getType() << " -> ", j->makeSound();
	std::cout << meta->getType() << " -> ", meta->makeSound();

	delete meta; delete i; delete j;
	std::cout << "----------------------------------" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	//will output the animal sound!
	std::cout << wrongAnimal->getType() << " -> ", wrongAnimal->makeSound();
	//will output the animal sound!
	std::cout << wrongCat->getType() << " -> ", wrongCat->makeSound();

	delete	wrongAnimal; delete wrongCat;
	return 0;
}
