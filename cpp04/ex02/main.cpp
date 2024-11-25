#include "A_Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main()
{
	Cat	cat;
	Dog	dog;

	cat.makeSound();
	dog.makeSound();
	
	// Animal animal; // not possible

	// animal.makeSound();

	return 0;
}
