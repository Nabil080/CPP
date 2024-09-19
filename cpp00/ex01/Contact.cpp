#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact(void)
{
    ;
}

Contact::Contact(bool input)
{
    if (!input)
        return ;
    this->first_name = this->getInput("first name");
    this->last_name = this->getInput("last name");
    this->nickname = this->getInput("nickname");
    this->darkest_secret = this->getInput("darkest secret");
    this->phone_number = this->getInput("phone number");
}

std::string Contact::getInput(std::string prompt)
{
    std::string input;

    std::cout << "Please enter your " << prompt << ": ";
    getline(std::cin, input);
    return (input);
}

void    Contact::showData(void)
{
    std::cout << "First name : " << this->first_name << std::endl;
    std::cout << "Last name : " << this->last_name << std::endl;
    std::cout << "Nickname : " << this->nickname << std::endl;
    std::cout << "Phone number : " << this->phone_number << std::endl;
    std::cout << "Darkest secret : " << this->darkest_secret << std::endl;
}