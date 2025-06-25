#include "fixed.hpp"

/* ~-~-~-~-~-~-~-~-~-~-~-~ CON/DESTRUCTORS ~-~-~-~-~-~-~-~-~-~-~-~ */

Fixed::Fixed() : rawvalue(0)
{
}

Fixed::Fixed(const int num)
{
	this->rawvalue = num << fracbits;
}

Fixed::Fixed(const float fnum)
{
	this->rawvalue = fnum * (1 << this->fracbits);
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
}

/* ~-~-~-~-~-~-~-~-~-~-~-~ FUNCTIONS ~-~-~-~-~-~-~-~-~-~-~-~ */

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
	return ((float)(this->rawvalue) / (1 << this->fracbits));
}

int Fixed::toInt(void) const
{
	return (this->rawvalue >> this->fracbits);
}

// Returns a reference to the smallest one.
// In case of equal values: return first one.
Fixed &Fixed::min(Fixed &fpn1, Fixed &fpn2)
{
	if (fpn1 <= fpn2)
		return (fpn1);
	else
		return (fpn2);
}

// Returns a reference to the smallest one.
// In case of equal values: return first one.
const Fixed &Fixed::min(const Fixed &fpn1, const Fixed &fpn2)
{
	if (fpn1 <= fpn2)
		return (fpn1);
	else
		return (fpn2);
}

// Returns a reference to the greatest one.
// In case of equal values: return first one.
Fixed &Fixed::max(Fixed &fpn1, Fixed &fpn2)
{
	if (fpn1 >= fpn2)
		return (fpn1);
	else
		return (fpn2);
}

// Returns a reference to the greatest one.
// In case of equal values: return first one.
const Fixed &Fixed::max(const Fixed &fpn1, const Fixed &fpn2)
{
	if (fpn1 >= fpn2)
		return (fpn1);
	else
		return (fpn2);
}

/* ~-~-~-~-~-~-~-~-~-~-~-~ OPERATORS ~-~-~-~-~-~-~-~-~-~-~-~ */

Fixed &Fixed::operator=(const Fixed &copy)
{
	rawvalue = copy.getRawBits();
	return (*this);
}

bool Fixed::operator==(const Fixed &copy) const
{
	return (this->rawvalue == copy.rawvalue);
}

bool Fixed::operator!=(const Fixed &copy) const
{
	return (this->rawvalue != copy.rawvalue);
}

bool Fixed::operator>=(const Fixed &copy) const
{
	return (this->rawvalue >= copy.rawvalue);
}

bool Fixed::operator<=(const Fixed &copy) const
{
	return (this->rawvalue <= copy.rawvalue);
}

bool Fixed::operator>(const Fixed &copy) const
{
	return (this->rawvalue > copy.rawvalue);
}

bool Fixed::operator<(const Fixed &copy) const
{
	return (this->rawvalue < copy.rawvalue);
}

Fixed Fixed::operator+(const Fixed &copy)
{
	Fixed temp;
	temp.rawvalue = this->rawvalue + copy.rawvalue;
	return (temp);
}

Fixed Fixed::operator-(const Fixed &copy)
{
	Fixed temp;
	temp.rawvalue = this->rawvalue - copy.rawvalue;
	return (temp);
}

Fixed Fixed::operator*(const Fixed &copy)
{
	Fixed temp;
	long long result = static_cast<long long>(this->rawvalue) * copy.rawvalue;
	temp.rawvalue = static_cast<int>(result >> fracbits);
	return (temp);
}

Fixed Fixed::operator/(const Fixed &copy)
{
	Fixed temp;
	temp.rawvalue = this->rawvalue / copy.toFloat();
	return (temp);
}

Fixed &Fixed::operator++()
{
	this->rawvalue += 1;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->rawvalue -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->rawvalue += 1;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->rawvalue -= 1;
	return (temp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &copy)
{
	return (out << copy.toFloat());
}
