#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(std::string name, int gradeexe, int gradesign);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	virtual ~AForm();

	std::string getName(void) const;
	int getGradesign(void) const;
	int getGradeexe(void) const;
	bool getSignedStatus(void) const;
	void setSignedStatus(bool status);
	void beSigned(Bureaucrat &b);
	virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &out, const AForm &copy);

#endif /* AFORM_HPP */