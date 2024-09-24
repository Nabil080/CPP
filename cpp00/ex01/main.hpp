#ifndef MAIN_HPP
# define MAIN_HPP

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"

# include "Contact.hpp"
# include "PhoneBook.hpp"
# include <iostream>
# include <string>
# include <cstdio>
# include <iomanip>
# include <cstdlib>

std::string getInput(std::string prompt);

#endif