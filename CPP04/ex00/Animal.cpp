#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(std::string typestr) : type(typestr)
{

	std::cout << "Animal type constructor" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal operator constructor" << std::endl;
	this->type = copy.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << this->type << ": average sound" << std::endl;
}

std::string Animal::getType(void) const
{
	if (this->type.empty())
		return ("<EMPTY>");
	return (this->type);
}