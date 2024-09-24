#include "main.hpp"


Contact::Contact(void)
{
    std::cout << GREEN "[Contact created]" RESET << std::endl;
}

Contact::~Contact(void)
{
    std::cout << RED "[Contact destroyed]" RESET << std::endl;
}

Contact::Contact(bool input)
{
    std::cout << GREEN "[Creating a Contact]" RESET << std::endl;
    if (!input)
        return ;
    this->first_name = getInput("Please enter your first name: ");
    this->last_name = getInput("Please enter your last name: ");
    this->nickname = getInput("Please enter your nickname: ");
    this->darkest_secret = getInput("Please enter your darkest secret: ");
    this->phone_number = getInput("Please enter your phone number: ");
    std::cout << GREEN << "[Contact created]" << RESET << std::endl;

}

void    Contact::showData(void)
{
    std::cout << "First name: " << this->first_name << std::endl;
    std::cout << "Last name: " << this->last_name << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone number: " << this->phone_number << std::endl;
    std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}