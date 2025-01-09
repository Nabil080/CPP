#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	AForm *form = new ShrubberyCreationForm("target");
	form->testForm();
	delete form;

	form = new PresidentialPardonForm("target");
	form->testForm();
	delete form;

	form = new RobotomyRequestForm("target");
	form->testForm();
	delete form;
	return 0;
}
