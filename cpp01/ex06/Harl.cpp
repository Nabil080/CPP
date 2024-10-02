#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
    size_t i = 0;
    this->messages_str[i] = "DEBUG";
    this->messages_fn[i++] = &Harl::debug;
    this->messages_str[i] = "INFO";
    this->messages_fn[i++] = &Harl::info;
    this->messages_str[i] = "WARNING";
    this->messages_fn[i++] = &Harl::warning;
    this->messages_str[i] = "ERROR";
    this->messages_fn[i++] = &Harl::error;
}

void    Harl::complain(std::string level)
{
    size_t  i;
    for (i = 0; i < this->fn_count; i++)
        if (this->messages_str[i] == level)
            break;
    switch (i)
    {
        case 0:
            (this->*messages_fn[0])();
        case 1:
            (this->*messages_fn[1])();
        case 2:
            (this->*messages_fn[2])();
        case 3:
            (this->*messages_fn[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
}