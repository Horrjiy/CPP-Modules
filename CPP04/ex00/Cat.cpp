#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(std::string typestr) : Animal(typestr)
{
	std::cout << "Cat type constructor" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat operator constructor" << std::endl;
	this->type = copy.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << this->type << ": meow." << std::endl;
}
