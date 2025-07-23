#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string type, std::string target)
{
	try
	{
		int option = 0;
		std::string names[] =
			{"pp", "prespard", "presidentialpardon", "PresidentialPardonForm",
			 "rr", "robreq", "robotomyrequest", "RobotomyRequestForm",
			 "sc", "shrub", "shrubberycreation", "ShrubberyCreationForm"};
		for (int i = 0; i <= 11; i++)
			if (type == names[i])
				option = (i / 4) + 1;
		switch (option)
		{
		case 1:
			return (new PresidentialPardonForm(target));
		case 2:
			return (new RobotomyRequestForm(target));
		case 3:
			return (new ShrubberyCreationForm(target));
		default:
			throw NoSuchFormException();
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern makeForm: " << e.what() << std::endl;
		return (nullptr);
	}
}

const char *Intern::NoSuchFormException::what() const noexcept
{
	return "this type of form doesn't exist";
}
