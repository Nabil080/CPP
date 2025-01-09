#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", this->sign_grade, this->exec_grade), target("default")
{
	std::cout << "Robotomy constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", this->sign_grade, this->exec_grade), target(target)
{
	std::cout << "Robotomy target constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), target(other.target)
{
	std::cout << "Robotomy copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor" << std::endl;
}

void RobotomyRequestForm::execute() const
{
	std::cout << "Drrrrrrll Drrrrrlll Drll Drl.." << std::endl;
	std::srand(time(0));
	if ((std::rand() % 100) < 50)
		std::cout << target << " has been robotomized !" << std::endl;
	else
		std::cout << "Robotomy failed..." << std::endl;
}
