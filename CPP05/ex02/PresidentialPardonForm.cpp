#include "PresidentialPardonForm.hpp"

// -~-~-~-~-~- Constructors -~-~-~-~-~- //

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target("NoTarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) \
: AForm("PresPard."+target, 5, 25), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	this->setSignedStatus(copy.getSignedStatus());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}


// -~-~-~-~-~- Functions -~-~-~-~-~- //

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if(!this->getSignedStatus())
		throw NotSigned();
	else if(executor.getGrade() > this->getGradeexe())
		throw GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox.\n";
}

// -~-~-~-~-~- Rest -~-~-~-~-~- //

const char *PresidentialPardonForm::GradeTooLowException::what() const noexcept
{
	return "grade is too low! (1-150)";
}

const char *PresidentialPardonForm::GradeTooHighException::what() const noexcept
{
	return "grade is too high! (1-150)";
}

const char *PresidentialPardonForm::NotSigned::what() const noexcept
{
	return "form is not signed yet";
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &copy)
{
	out << copy.getName() << ", PresidentialPardonForm sign grade " << copy.getGradesign() << ", execution grade " << copy.getGradeexe() << ".";
	return (out);
}
