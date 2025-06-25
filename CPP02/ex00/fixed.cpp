#include "fixed.hpp"

Fixed::Fixed() : rawvalue(0)
{
	std::cout << "default constructor" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "copy constructor" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "copy assignment constructor" << std::endl;
	rawvalue = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "default destructor" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits" << std::endl;
	return (this->rawvalue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits" << std::endl;
	this->rawvalue = raw;
}
