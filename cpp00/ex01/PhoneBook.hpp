#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
		int		count;	
		Contact	contacts[8];
	public:
		PhoneBook(void);
		void	showInputs(void);
		void	addContact(Contact contact);
		void	showContacts(void);
};

#endif