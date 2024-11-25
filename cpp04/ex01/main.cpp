#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main()
{
	const size_t	count = 100;

	Animal	*animals[count];

	for (size_t i = 0; i < count / 2; i++)
		animals[i] = new Dog;
	for (size_t i = count / 2; i < count; i++)
		animals[i] = new Cat;

	for (size_t i = 0; i < count / 2; i++)
		std::cout << static_cast<Dog*>(animals[i])->getBrain()->getIdea(0) << std::endl;
	for (size_t i = count / 2; i < count; i++)
		std::cout << static_cast<Cat*>(animals[i])->getBrain()->getIdea(0) << std::endl;

	for (size_t i = 0; i < count; i++)
		delete animals[i];

	// deep copy test
	Dog basic;
	{
		Dog	copy = basic;
	}
	std::cout << "Basic brain -> " << basic.getBrain()->getIdea(0) << std::endl;

	return 0;
}
