#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
		/*variables*/
		size_t				count;
		static const size_t		max_count;
		static const size_t		col_width;
		Contact				contacts[8];
		/*functions*/
		void    			printColumn(std::string str, bool sep);
		void	    		printLine(bool sep);
		void				printOneContact(void);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(Contact contact);
		void	printContacts(void);
};

#endif