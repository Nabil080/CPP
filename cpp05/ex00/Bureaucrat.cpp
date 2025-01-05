#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat() : name("undefined") {
  this->grade = this->lowest_grade;
}

Bureaucrat::Bureaucrat(std::string name) : name(name) {
  this->grade = this->lowest_grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
  if (grade > lowest_grade)
    throw GradeTooLowException();
  if (grade < highest_grade)
    throw GradeTooHighException();
  this->grade = grade;
}

Bureaucrat::~Bureaucrat() { ; }

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other) {
  out << other.getName() << ", bureaucrat grade " << other.getGrade();
  return (out);
}

std::string Bureaucrat::getName() const { return (this->name); }

int Bureaucrat::getGrade() const { return (this->grade); }

void Bureaucrat::upgrade() {
  if (grade == highest_grade)
    throw GradeTooHighException();
  this->grade--;
}

void Bureaucrat::downgrade() {
  if (grade == lowest_grade)
    throw GradeTooLowException();
  this->grade++;
}

// Exceptions

const std::string Bureaucrat::GradeTooHighException::message =
    "A grade can't be higher than " + std::to_string(Bureaucrat::highest_grade);

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return this->message.c_str();
}

const std::string Bureaucrat::GradeTooLowException::message =
    "A grade can't be lower than " + std::to_string(Bureaucrat::lowest_grade);

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return this->message.c_str();
}
