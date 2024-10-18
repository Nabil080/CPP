#include "main.hpp"

int main(void)
{
	PhoneBook	PhoneBook;
	std::string	input;

	do
	{
        input = getInput("Enter a " BLUE "command" RESET " > ");
		if (input == "ADD")
			PhoneBook.addContact(Contact(true));
		if (input == "SEARCH")
			PhoneBook.printContacts();
	} while (input != "EXIT");

	return (0);
}

std::string getInput(std::string prompt)
{
    std::string input;
    do
    {
        std::cout << prompt;
        getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cin.clear();
            clearerr(stdin);
            std::cout << std::endl;
        }
    }
    while (input.empty());
    return (input);
}
