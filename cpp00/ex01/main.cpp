#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook	pb;
	std::string	input;

	do
	{
		pb.showInputs();
		getline(std::cin, input);
		if (std::cin.eof())
			return (1);
		if (input == "ADD")
			pb.addContact(Contact(true));
		if (input == "SEARCH")
			pb.printContacts();
	} while (input != "EXIT");
	return (0);
}
