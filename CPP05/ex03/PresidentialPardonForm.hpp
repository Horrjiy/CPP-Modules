#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

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

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &copy);

#endif	/* PRESIDENTIALPARDONFORM_HPP */