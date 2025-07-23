#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

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
	void signForm(Form &f);

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