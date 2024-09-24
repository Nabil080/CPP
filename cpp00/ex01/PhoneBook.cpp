#include "main.hpp"

const size_t    PhoneBook::max_count = 7;
const size_t    PhoneBook::col_width = 10;

PhoneBook::PhoneBook(void)
{
    std::cout << "Creating an empty PhoneBook (" << max_count + 1 << " contacts maximum)\n";
    std::cout << "Use the PhoneBook with those commands : " BLUE "[ADD] [SEARCH] [EXIT]" RESET "\n\n";
    this->count = 0;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Destroying your PhoneBook (data lost forever)\n";
}

void    PhoneBook::addContact(Contact contact)
{
    for (int i = this->count; i > 0; i--)
        this->contacts[i] = this->contacts[i - 1];
    if (this->count < this->max_count)
        this->count++;
    this->contacts[0] = contact;
    std::cout << "[" << contact.first_name << "] was sucessfully added in the PhoneBook\n";
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
            else
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
    for (size_t i = 0; i <= max_count; i++)
    {
        std::cout << "|";
        std::cout << std::setfill(' ') << std::setw(this->col_width) << i;
        this->printColumn(this->contacts[i].first_name, false);
        this->printColumn(this->contacts[i].last_name, false);
        this->printColumn(this->contacts[i].nickname, true);
        std::cout << std::endl;
    }
    this->printLine(false);
    if (this->count > 0)
        this->printOneContact();
}

void    PhoneBook::printOneContact(void)
{
    int    index;
    char    *p;
    std::string input;
    do
    {
        input = getInput("Enter an index to display a contact: ");
        index = strtol(input.c_str(), &p, 10);
    }
    while(*p || index < 0 || index >= (int)this->count);
    this->contacts[index].showData();
}
