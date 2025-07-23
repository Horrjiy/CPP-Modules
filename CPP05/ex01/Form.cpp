#include "Form.hpp"

Form::Form() : name("defaultNoName"), gradeexe(1), gradesign(1)
{
}

Form::Form(std::string name, int gradeexe, int gradesign) : name(name), gradeexe(gradeexe), gradesign(gradesign)
{
	if (gradesign > 150 || gradeexe > 150)
		throw GradeTooLowException();
	if (gradesign < 1 || gradesign < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &copy) : name("defaultNoName"), gradeexe(1), gradesign(1)
{
	*this = copy;
}

Form &Form::operator=(const Form &copy)
{
	this->isSigned = copy.isSigned;
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName(void) const
{
	return (this->name);
}

int Form::getGradeexe(void) const
{
	return (this->gradeexe);
}

int Form::getGradesign(void) const
{
	return (this->gradesign);
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->gradesign)
	{

		if (this->isSigned)
		{
			throw AlreadySigned();
			return;
		}
		this->isSigned = true;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &copy)
{
	out << copy.getName() << ", form sign grade " << copy.getGradesign() << ", execution grade " << copy.getGradeexe() << ".\n";
	return (out);
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return "grade is too low! (1-150)";
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return "grade is too high! (1-150)";
}

const char *Form::AlreadySigned::what() const noexcept
{
	return "Form is already signed!";
}

