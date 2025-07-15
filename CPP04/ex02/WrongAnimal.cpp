#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string typestr) : type(typestr)
{

	std::cout << "WrongAnimal type constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal operator constructor" << std::endl;
	this->type = copy.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << this->type << ": average wrong sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	if (this->type.empty())
		return ("<EMPTY>");
	return (this->type);
}
