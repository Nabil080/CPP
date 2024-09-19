#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string darkest_secret;
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
		Contact(void);
		Contact(bool input);
		std::string getInput(std::string prompt);
		void		showData(void);
};

#endif