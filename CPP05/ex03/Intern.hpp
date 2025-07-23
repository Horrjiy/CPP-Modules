#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
	~Intern();

	AForm *makeForm(std::string type, std::string target);

	class NoSuchFormException : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};
};

#endif /* INTERN_HPP*/