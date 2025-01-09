#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class Form
{
  private:
	const std::string name;
	bool is_signed;
	const int sign_grade;
	const int exec_grade;

  public: // canonical form
	Form();
	Form(const Form &other);
	~Form();

	Form &operator=(const Form &other);

  public: // other constructors
	Form(std::string name);
	Form(std::string name, int sign_grade, int exec_grade);

  public: // getters
	const std::string getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

  public: // methods
	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	  public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	  public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif // !FORM_HPP
