#include "Contact.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Contact	c1;
	std::string	line;

	do
	{
		getline(std::cin, line);
		if (!line.compare("ADD"))
			std::cout << "Adding a contact" << std::endl;
		else
			std::cout << line << std::endl;
	} while (line.compare("EXIT"));
	return (0);
}
