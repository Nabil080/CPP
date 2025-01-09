#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat
{
  public:
	static const int highest_grade = 1;
	static const int lowest_grade = 150;

  private:
	const std::string name;
	int grade;

  public:
	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

  public:
	Bureaucrat &operator=(const Bureaucrat &other);

  public:
	void upgrade();
	void downgrade();
	void tryAndSignForm(AForm &form);

  public:
	std::string getName() const;
	int getGrade() const;

	class GradeTooHighException : public std::exception
	{
	  private:
		static const std::string message;

	  public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	  private:
		static const std::string message;

	  public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);

#endif
