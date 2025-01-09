#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", this->sign_grade, this->exec_grade), target("default")
{
	std::cout << "Shrubbery constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", this->sign_grade, this->exec_grade), target(target)
{
	std::cout << "Shrubbery target constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), target(other.target)
{
	std::cout << "Shrubbery copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery destructor" << std::endl;
}

void ShrubberyCreationForm::execute() const
{
	std::ofstream outfile((target + "_shrubbery").c_str());
	if (!outfile)
		return;
	outfile << "↟↟ASCII↟↟TREES↟↟";
	outfile.close();
}
