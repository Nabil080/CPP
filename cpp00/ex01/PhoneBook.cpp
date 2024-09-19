#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook(void)
{
    this->count = 0;
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

void    PhoneBook::showContacts(void)
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << "-----------\n";
        this->contacts[i].showData();    
    }
}
