#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string name, int gradeexe, int gradesign);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form();

	std::string getName(void) const;
	int getGradesign(void) const;
	int getGradeexe(void) const;
	void beSigned(Bureaucrat &b);

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
	class AlreadySigned : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};

private:
	const std::string name;
	bool isSigned = false;
	const int gradeexe;
	const int gradesign;
};

std::ostream &operator<<(std::ostream &out, const Form &copy);

#endif /* FORM_HPP */