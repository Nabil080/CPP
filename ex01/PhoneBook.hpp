#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
	public:
		std::string darkest_secret;
		long	 	phone_number;
};

#endif