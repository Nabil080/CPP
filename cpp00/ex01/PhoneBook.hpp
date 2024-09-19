#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
		size_t		count;
		size_t		col_width;
		Contact	contacts[8];
	public:
		PhoneBook(void);
		void	showInputs(void);
		void	addContact(Contact contact);
		void    printColumn(std::string str, bool sep);
		void	printContacts(void);
};

#endif