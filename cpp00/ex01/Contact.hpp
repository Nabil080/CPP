#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string darkest_secret;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
	public:
		Contact(void);
		Contact(bool input);
		~Contact(void);
		void		showData(void);

		friend class PhoneBook;
};

#endif