#include "Intern.hpp"

int main(void)
{
	Intern intern;
	AForm *form;

	form = intern.makeForm("random", "target");
	if (form)
		delete form;
	form = intern.makeForm("robotomy request", "Bender");
	if (form)
		delete form;
	form = intern.makeForm("shrubbery creation", "Bender");
	if (form)
		delete form;
	form = intern.makeForm("presidential pardon", "Bender");
	if (form)
		delete form;
	return 0;
}
