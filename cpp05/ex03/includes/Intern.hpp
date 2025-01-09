#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
class Intern
{
  public: // canon
	Intern();
	Intern(Intern const &other);
	~Intern();
	Intern &operator=(Intern const &other);

  public:
	AForm *makeForm(std::string form_name, std::string target);
	AForm *ShrubberyCreationForm(std::string target);
	AForm *PresidentialPardonForm(std::string target);
	AForm *RobotomyRequestForm(std::string target);
};

#endif // !INTERN_HPP
