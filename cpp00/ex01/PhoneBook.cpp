#include "main.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "Creating an empty PhoneBook (8 contacts maximum)\n";
    std::cout << "Use the PhoneBook with those commands : [ADD] [SEARCH] [EXIT]\n\n";
    this->count = 0;
    this->col_width = 10;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Destroying your PhoneBook (data lost forever)\n";
}

void    PhoneBook::addContact(Contact contact)
{
    for (int i = this->count; i > 0; i--)
        this->contacts[i] = this->contacts[i - 1];
    if (this->count < 7)
        this->count++;
    this->contacts[0] = contact;
    std::cout << contact.first_name << " was sucessfully added in the PhoneBook\n";
}

void    PhoneBook::printColumn(std::string str, bool sep)
{
    std::cout << "|";
    if (str.size() > this->col_width)
        std::cout << str.substr(0, this->col_width - 1) << ".";
    else
        std::cout << std::setfill(' ') << std::setw(this->col_width) << str;
    if (sep)
        std::cout  << "|";
}

void    PhoneBook::printLine(bool inside)
{
    if (inside)
        std::cout << "|";
    else
        std::cout << " ";
    for (size_t i = 0; i < 4 * this->col_width; i++)
    {
        if (i && i % this->col_width == 0)
        {
            if (inside)
                std::cout << "|";
            else if (!inside)
                std::cout << "_";
        } 
        std::cout << "_";
    }
    if (inside)
        std::cout << "|";
    std::cout << std::endl;
}

void    PhoneBook::printContacts(void)
{
    this->printLine(false);
    this->printColumn("Index", false);
    this->printColumn("First name", false);
    this->printColumn("Last name", false);
    this->printColumn("Nickname", true);
    std::cout << std::endl;
    this->printLine(true);
    for (int i = 0; i < 8; i++)
    {
        std::cout << "|";
        std::cout << std::setfill(' ') << std::setw(this->col_width) << i;
        this->printColumn(this->contacts[i].first_name, false);
        this->printColumn(this->contacts[i].last_name, false);
        this->printColumn(this->contacts[i].nickname, true);
        std::cout << std::endl;
    }
    this->printLine(false);
    int    index;
    char    *p;
    do
        index = strtol(getInput("Select a valid index: ").c_str(), &p, 10);
    while(*p || index < 0 || index > (int)this->count);
    this->contacts[index].showData();
}
