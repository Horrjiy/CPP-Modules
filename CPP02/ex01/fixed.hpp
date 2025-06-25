#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float fnum);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int rawvalue;
	static const int fracbits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &copy);

#endif /* FIXED_HPP */