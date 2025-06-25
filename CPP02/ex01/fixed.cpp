#include "fixed.hpp"

Fixed::Fixed() : rawvalue(0)
{
	std::cout << "default constructor" << std::endl;
}

Fixed::Fixed(const int num)
{
	setRawBits(num);
	std::cout << "int constructor" << std::endl;
	this->rawvalue = num << fracbits;
}

Fixed::Fixed(const float fnum)
{
	setRawBits(fnum);
	std::cout << "float constructor" << std::endl;
	this->rawvalue = fnum * (1 << this->fracbits);
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "copy constructor" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "destructor" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->rawvalue);
}

void Fixed::setRawBits(int const raw)
{
	this->rawvalue = raw;
}

float Fixed::toFloat(void) const
{
	return((float)(this->rawvalue) / (1 << this->fracbits));
}

int Fixed::toInt(void) const
{
	return(this->rawvalue >> this->fracbits);
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "copy assignment constructor" << std::endl;
	rawvalue = copy.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &copy)
{
	return(out << copy.toFloat());
}
