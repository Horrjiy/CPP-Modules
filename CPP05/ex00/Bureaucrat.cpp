#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("defaultNoName"), grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) { *this = copy; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->grade = copy.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::gradeProm()
{
	grade--;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::gradeDegr()
{
	grade++;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();

}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &copy)
{
	out << copy.getName() << ", bureaucrat grade " << copy.getGrade() << ".\n";
	return(out);
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "grade is too low! (1-150)";
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "grade is too high! (1-150)";
}
