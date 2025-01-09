#include "Form.hpp"
#include <iostream>
#include <ostream>

// canonical form

Form::Form()
    : name("undefined"), is_signed(false), sign_grade(Bureaucrat::lowest_grade),
      exec_grade(Bureaucrat::lowest_grade) {
  std::cout << "Form constructor\n";
}

Form::Form(const Form &other)
    : name(other.name), is_signed(other.is_signed),
      sign_grade(other.sign_grade), exec_grade(other.exec_grade) {
  std::cout << "Form copy constructor\n";
}

Form::~Form() { std::cout << "Form destructor\n"; }

Form &Form::operator=(const Form &other) {
  if (this == &other)
    return (*this);
  this->is_signed = other.is_signed;
  return (*this);
}

// other constructors

Form::Form(std::string name)
    : name(name), is_signed(false), sign_grade(Bureaucrat::lowest_grade),
      exec_grade(Bureaucrat::lowest_grade) {
  std::cout << "Form constructor\n";
}

Form::Form(std::string name, int sign_grade, int exec_grade)
    : name(name), is_signed(false), sign_grade(sign_grade),
      exec_grade(exec_grade) {
  if (sign_grade > Bureaucrat::lowest_grade ||
      exec_grade > Bureaucrat::lowest_grade)
    throw GradeTooLowException();
  if (sign_grade < Bureaucrat::highest_grade ||
      exec_grade < Bureaucrat::highest_grade)
    throw GradeTooHighException();
  std::cout << "Form constructor\n";
}
// getters

const std::string Form::getName() const { return (this->name); }
bool Form::isSigned() const { return (this->is_signed); }
int Form::getSignGrade() const { return (this->sign_grade); }
int Form::getExecGrade() const { return (this->exec_grade); }

// methods

void Form::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->sign_grade)
    throw(GradeTooLowException());
  this->is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &other) {
  out << other.getName() << ", form with sign_grade of " << other.getSignGrade()
      << " and exec_grade of " << other.getExecGrade();
  return (out);
}
