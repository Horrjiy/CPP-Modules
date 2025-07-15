#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(std::string typestr) : WrongAnimal(typestr)
{
	std::cout << "WrongCat type constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat operator constructor" << std::endl;
	this->type = copy.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << this->type << ": meow." << std::endl;
}
