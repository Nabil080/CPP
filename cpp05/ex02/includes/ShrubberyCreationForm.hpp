#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
class ShrubberyCreationForm : public AForm
{
  public:
	static const int sign_grade = 145;
	static const int exec_grade = 137;

  private:
	std::string target;

  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;
};

#endif // !SHRUBBERYCREATIONFORM_HPP
