#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	int i = 0;
	std::string form_names[3];
	AForm *(Intern::*form_constructors[3])(std::string);

	form_names[i] = "shrubbery creation";
	form_constructors[i++] = &Intern::ShrubberyCreationForm;
	form_names[i] = "presidential pardon";
	form_constructors[i++] = &Intern::PresidentialPardonForm;
	form_names[i] = "robotomy request";
	form_constructors[i++] = &Intern::RobotomyRequestForm;

	while (i-- > 0)
	{
		if (form_names[i] == form_name)
		{
			std::cout << "Intern creates " << form_name << " form" << std::endl;
			return ((this->*form_constructors[i])(target));
		}
	}
	std::cout << form_name << " doesn't exist" << std::endl;
	return (NULL);
}

AForm *Intern::ShrubberyCreationForm(std::string target)
{
	return (new class ShrubberyCreationForm(target));
}

AForm *Intern::PresidentialPardonForm(std::string target)
{
	return (new class PresidentialPardonForm(target));
}

AForm *Intern::RobotomyRequestForm(std::string target)
{
	return (new class RobotomyRequestForm(target));
}
