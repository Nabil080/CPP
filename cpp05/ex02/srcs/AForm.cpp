#include "AForm.hpp"
#include <iostream>
#include <ostream>

// canonical form

AForm::AForm()
	: name("undefined"), is_signed(false), sign_grade(Bureaucrat::lowest_grade), exec_grade(Bureaucrat::lowest_grade)
{
	std::cout << "Form constructor\n";
}

AForm::AForm(const AForm &other)
	: name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
	std::cout << "Form copy constructor\n";
}

AForm::~AForm()
{
	std::cout << "Form destructor\n";
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return (*this);
	this->is_signed = other.is_signed;
	return (*this);
}

// other constructors

AForm::AForm(std::string name)
	: name(name), is_signed(false), sign_grade(Bureaucrat::lowest_grade), exec_grade(Bureaucrat::lowest_grade)
{
	std::cout << "Form constructor\n";
}

AForm::AForm(std::string name, int sign_grade, int exec_grade)
	: name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade > Bureaucrat::lowest_grade || exec_grade > Bureaucrat::lowest_grade)
		throw GradeTooLowException();
	if (sign_grade < Bureaucrat::highest_grade || exec_grade < Bureaucrat::highest_grade)
		throw GradeTooHighException();
	std::cout << "Form constructor\n";
}
// getters

const std::string AForm::getName() const
{
	return (this->name);
}
bool AForm::isSigned() const
{
	return (this->is_signed);
}
int AForm::getSignGrade() const
{
	return (this->sign_grade);
}
int AForm::getExecGrade() const
{
	return (this->exec_grade);
}

// methods

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->sign_grade)
		throw(GradeTooLowException());
	this->is_signed = true;
}

void AForm::tryAndExecute(Bureaucrat const &executor) const
{
	if (this->is_signed == false)
		throw(NotSignedException());
	if (executor.getGrade() > this->exec_grade)
		throw(GradeTooLowException());
	this->execute(executor);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &other)
{
	out << other.getName() << ", " << (other.isSigned() ? "signed" : "unsigned") << " form with sign_grade of "
		<< other.getSignGrade() << " and exec_grade of " << other.getExecGrade();
	return (out);
}
