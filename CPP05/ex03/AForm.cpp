#include "AForm.hpp"


// -~-~-~-~-~- Constructors -~-~-~-~-~- //

AForm::AForm() : name("defaultNoName"), gradeexe(1), gradesign(1)
{
}

AForm::AForm(std::string name, int gradeexe, int gradesign) : name(name), gradeexe(gradeexe), gradesign(gradesign)
{
	if (gradesign > 150 || gradeexe > 150)
		throw GradeTooLowException();
	if (gradesign < 1 || gradesign < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &copy) : name("defaultNoName"), gradeexe(1), gradesign(1)
{
	*this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
	this->isSigned = copy.isSigned;
	return (*this);
}

AForm::~AForm()
{
}


// -~-~-~-~-~- Functions -~-~-~-~-~- //

std::string AForm::getName(void) const
{
	return (this->name);
}

int AForm::getGradeexe(void) const
{
	return (this->gradeexe);
}

int AForm::getGradesign(void) const
{
	return (this->gradesign);
}

void AForm::beSigned(Bureaucrat &b)
{
		if (b.getGrade() <= this->gradesign)
	{

		if (this->isSigned)
		{
			throw AlreadySigned();
		}
		this->isSigned = true;
	}
	else
		throw GradeTooLowException();
}

bool AForm::getSignedStatus(void) const
{
	return(this->isSigned);
}

void AForm::setSignedStatus(bool status)
{
	this->isSigned = status;
}

//-~-~-~-~-~- Rest -~-~-~-~-~- //

std::ostream &operator<<(std::ostream &out, const AForm &copy)
{
	out << copy.getName() << ", Aform sign grade " << copy.getGradesign() << ", execution grade " << copy.getGradeexe() << ".\n";
	return (out);
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return "grade is too low! (1-150)";
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return "grade is too high! (1-150)";
}

const char *AForm::AlreadySigned::what() const noexcept
{
	return "Form is already signed!";
}
