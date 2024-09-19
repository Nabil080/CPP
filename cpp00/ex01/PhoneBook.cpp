#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook(void)
{
    this->count = 0;
    this->col_width = 10;
}

void    PhoneBook::showInputs(void)
{
    std::cout << "Inputs : ADD | SEARCH | EXIT" << std::endl;
}

void    PhoneBook::addContact(Contact contact)
{
    for (int i = this->count; i > 0; i--)
        this->contacts[i] = this->contacts[i - 1];
    if (this->count < 7)
        this->count++;
    this->contacts[0] = contact;
}

void    PhoneBook::printColumn(std::string str, bool sep)
{
    if (str.size() > this->col_width)
        std::cout << str.substr(0, this->col_width - 1) << ".";
    else
        std::cout << std::setfill(' ') << std::setw(this->col_width) << str;
    if (sep)
        std::cout << "|";
}

void    PhoneBook::printContacts(void)
{
    std::cout << std::endl << std::endl;
    this->printColumn("Index", true);
    this->printColumn("First name", true);
    this->printColumn("Last name", true);
    this->printColumn("Nickname", false);
    std::cout << std::endl << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setfill(' ') << std::setw(this->col_width) << i << "|";
        this->printColumn(this->contacts[i].first_name, true);
        this->printColumn(this->contacts[i].last_name, true);
        this->printColumn(this->contacts[i].nickname, false);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
