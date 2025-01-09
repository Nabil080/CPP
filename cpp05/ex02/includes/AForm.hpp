#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{
  private:
	const std::string name;
	bool is_signed;
	const int sign_grade;
	const int exec_grade;

  public: // canonical form
	AForm();
	AForm(const AForm &other);
	~AForm();

	AForm &operator=(const AForm &other);

  public: // other constructors
	AForm(std::string name);
	AForm(std::string name, int sign_grade, int exec_grade);

  public: // getters
	const std::string getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

  public: // methods
	void beSigned(Bureaucrat &bureaucrat);
	void tryAndExecute(Bureaucrat const &executor) const;
	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class NotSignedException : public std::exception
	{
	  public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &other);

#endif // !FORM_HPP
