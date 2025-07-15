#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(std::string typestr) : Animal(typestr)
{
	std::cout << "Dog type constructor" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog operator constructor" << std::endl;
	this->type = copy.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << this->type << ": bark." << std::endl;
}

