#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", this->sign_grade, this->exec_grade), target("default")
{
	std::cout << "Presidential constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", this->sign_grade, this->exec_grade), target(target)
{
	std::cout << "Presidential target constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), target(other.target)
{
	std::cout << "Presidential copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential destructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << "Executing PresidentialPardonForm " << executor << std::endl;
}
