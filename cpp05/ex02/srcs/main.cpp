#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void callTest(std::string name, void (*f)())
{
	std::cout << "--- " << name << " test ---" << std::endl;
	{
		f();
	}
	std::cout << "--- END ---" << std::endl;
}

namespace tests
{
const Bureaucrat noob("noob", 150);
const Bureaucrat boss("boss", 1);

void shrubberyCreationTest()
{
	ShrubberyCreationForm form;

	// unsigned test
	std::cout << noob << " executing " << form << std::endl;
	try
	{
		form.tryAndExecute(noob);
		std::cout << "Success !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	boss.tryAndSignForm(form);
	// grade test
	std::cout << noob << " executing " << form << std::endl;
	try
	{
		form.tryAndExecute(noob);
		std::cout << "Success !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// correct execution
	boss.executeForm(form);
}

} // namespace tests

int main(void)
{
	// AForm *form = new ShrubberyCreationForm("target");
	callTest("ShrubberyCreation ", tests::shrubberyCreationTest);
	return 0;
}
