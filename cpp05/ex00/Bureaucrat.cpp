#include "Bureaucrat.hpp"
// #include <exception>

Bureaucrat::Bureaucrat() : name("undefined") {
  this->grade = this->lowest_grade;
}

Bureaucrat::Bureaucrat(std::string name) : name(name) {
  this->grade = this->lowest_grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
  // TODO throw exception on error
  // if (grade > lowest_grade)
  //     throw std::exception;
  // if (grade < highest_grade)
  //     throw std::exception;
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
  // TODO throw exception
  if (grade == highest_grade)
    throw grade;
  this->grade--;
}

void Bureaucrat::downgrade() {
  // TODO throw exception
  if (grade == lowest_grade)
    throw grade;
  this->grade++;
}
