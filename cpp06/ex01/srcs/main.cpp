#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data starting_data;

	starting_data.name = "Xavier";
	starting_data.number = 42;
	starting_data.boolean = true;

	std::cout << "Adress: " << &starting_data << std::endl;
	std::cout << starting_data << std::endl;

	uintptr_t uint_ptr = Serializer::serialize(&starting_data);
	Data *data_ptr = Serializer::deserialize(uint_ptr);

	std::cout << "Adress: " << data_ptr << std::endl;
	std::cout << *data_ptr << std::endl;

	return (0);
}
