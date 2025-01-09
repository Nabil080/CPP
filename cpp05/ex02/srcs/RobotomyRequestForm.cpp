#include "RobotomyRequestForm.hpp"
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

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << "Executing RobotomyRequestFOrm " << executor << std::endl;
}
