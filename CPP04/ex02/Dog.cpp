#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor" << std::endl;
	this->dogbrain = new Brain();
}

Dog::Dog(std::string typestr) : Animal(typestr)
{
	std::cout << "Dog type constructor" << std::endl;
	this->dogbrain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor" << std::endl;
	this->dogbrain = new Brain();
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog operator constructor" << std::endl;
	this->type = copy.type;
	*(this->dogbrain) = *(copy.dogbrain);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
	delete this->dogbrain;
}

void Dog::makeSound(void) const
{
	std::cout << this->type << ": bark." << std::endl;
}

Brain *Dog::getBrain(void)
{
	return(this->dogbrain);
}