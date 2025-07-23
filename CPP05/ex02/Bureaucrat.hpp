#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();

	std::string getName(void) const;
	int getGrade(void) const;
	void gradeProm();
	void gradeDegr();
	void signForm(AForm &f);
	void executeForm(AForm const &form);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};

private:
	const std::string name;
	int grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &copy);

#endif /* BUREAUCRAT_HPP */