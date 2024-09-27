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
    for (size_t i = 0; i < this->fn_count; i++)
        if (this->messages_str[i] == level)
            (this->*messages_fn[i])();
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