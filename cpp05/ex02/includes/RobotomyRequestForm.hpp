#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
class RobotomyRequestForm : public AForm
{
  public:
	static const int sign_grade = 145;
	static const int exec_grade = 137;

  private:
	std::string target;

  public:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const;
};

#endif // !ROBOTOMYREQUESTFORM_HPP
