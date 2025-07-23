#include "RobotomyRequestForm.hpp"

//-~-~-~-~-~- Constructors -~-~-~-~-~- //

RobotomyRequestForm::RobotomyRequestForm() : AForm(), target("NoTarget")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) \
: AForm("RobReq."+target, 45, 72), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm()
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	this->setSignedStatus(copy.getSignedStatus());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


//-~-~-~-~-~- Functions -~-~-~-~-~- //

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if(!this->getSignedStatus())
		throw NotSigned();
	else if(executor.getGrade() > this->getGradeexe())
		throw GradeTooLowException();
	std::cout << "* DRRRRRRRRRRRRRZZZ *\n";
	auto timenow = std::chrono::system_clock::now().time_since_epoch();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(timenow).count();
	if(ms % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}

//-~-~-~-~-~- Rest -~-~-~-~-~- //

const char *RobotomyRequestForm::GradeTooLowException::what() const noexcept
{
	return "grade is too low! (1-150)";
}

const char *RobotomyRequestForm::GradeTooHighException::what() const noexcept
{
	return "grade is too high! (1-150)";
}

const char *RobotomyRequestForm::NotSigned::what() const noexcept
{
	return "form is not signed yet";
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &copy)
{
	out << copy.getName() << ", RobotomyRequestForm sign grade " << copy.getGradesign() << ", execution grade " << copy.getGradeexe() << ".";
	return (out);
}
