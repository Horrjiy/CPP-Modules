#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <chrono>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string name);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const override;

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
	class NotSigned : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};

private:
	const std::string target;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &copy);

#endif	/* ROBOTOMYREQUESTFORM_HPP */