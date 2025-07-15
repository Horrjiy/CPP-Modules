#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor" << std::endl;
	this->catbrain = new Brain();
}

Cat::Cat(std::string typestr) : Animal(typestr)
{
	std::cout << "Cat type constructor" << std::endl;
	this->catbrain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor" << std::endl;
	this->catbrain = new Brain();
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat operator constructor" << std::endl;
	this->type = copy.type;
	*(this->catbrain) = *(copy.catbrain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	delete this->catbrain;
}

void Cat::makeSound(void) const
{
	std::cout << this->type << ": meow." << std::endl;
}

Brain *Cat::getBrain(void)
{
	return(this->catbrain);
}