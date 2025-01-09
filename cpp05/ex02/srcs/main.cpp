#include "AForm.hpp"
#include "Bureaucrat.hpp"
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

void initialize_test()
{
	AForm base("base_form");
	std::cout << base << std::endl;

	try
	{
		AForm too_low("Too low", 500, 500);
		std::cout << too_low << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		AForm too_high("Too high", 0, 0);
		std::cout << too_high << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void sign_test()
{
	AForm boss_form("boss_form", 1, 1);
	AForm noob_form("noob_form", 150, 150);

	Bureaucrat boss("boss", 1);
	Bureaucrat noob("noob", 150);

	noob.tryAndSignForm(boss_form);
	boss.tryAndSignForm(boss_form);
	noob_form.beSigned(noob);
	std::cout << noob_form << std::endl;
}

} // namespace tests

int main(void)
{
	AForm form;

	return (0);

	callTest("Initialize", tests::initialize_test);
	callTest("Sign", tests::sign_test);
	return 0;
}
