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
	bool operator==(const Fixed &copy) const;
	bool operator>=(const Fixed &copy) const;
	bool operator<=(const Fixed &copy) const;
	bool operator>(const Fixed &copy) const;
	bool operator<(const Fixed &copy) const;
	bool operator!=(const Fixed &copy) const;
	Fixed operator+(const Fixed &copy);
	Fixed operator-(const Fixed &copy);
	Fixed operator*(const Fixed &copy);
	Fixed operator/(const Fixed &copy);
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed &min(Fixed &fpn1, Fixed &fpn2)  ;
	static const Fixed &min(const Fixed &fpn1, const Fixed &fpn2)  ;
	static Fixed &max(Fixed &fpn1, Fixed &fpn2)  ;
	static const Fixed &max(const Fixed &fpn1, const Fixed &fpn2) ;

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