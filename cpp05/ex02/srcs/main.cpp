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

	form.tryAndExecute(noob);
}

} // namespace tests

int main(void)
{
	callTest("ShrubberyCreation ", tests::shrubberyCreationTest);
	return 0;
}
