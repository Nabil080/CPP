#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
class PresidentialPardonForm : public AForm
{
  public:
	static const int sign_grade = 25;
	static const int exec_grade = 5;

  private:
	std::string target;

  public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();

  protected:
	void execute() const;
};

#endif // !PRESIDENTIALPARDONFORM_HPP
