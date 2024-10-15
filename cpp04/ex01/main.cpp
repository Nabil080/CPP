#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main()
{
	Animal	*animals[100];

	for (size_t i = 0; i < 50; i++)
		animals[i] = new Dog;
	for (size_t i = 50; i < 100; i++)
		animals[i] = new Cat;

	std::cout << static_cast<Dog*>(animals[0])->brain->ideas[0] << std::endl;
	std::cout << static_cast<Cat*>(animals[50])->brain->ideas[0] << std::endl;

	for (size_t i = 0; i < 100; i++)
		delete animals[i];

	return 0;
}
