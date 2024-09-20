#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
		size_t		count;
		size_t		col_width;
		Contact		contacts[8];
		void    	printColumn(std::string str, bool sep);
		void	    printLine(bool sep);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(Contact contact);
		void	printContacts(void);
};

#endif