#include "fixed.hpp"

void subject_tests(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

void own_tests(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c = a + b;
	Fixed d(1234.5678f);
	Fixed f(20.40f);
	std::cout << "a + b:		" << a.toFloat() + b.toFloat() << std::endl;
	std::cout << "c:		" << c << std::endl;
	std::cout << "d:		" << d << std::endl;
	for (int i = 0; i < 256; i++)
		d++;
		std::cout << "256x d++:	" << d << std::endl << std::endl;
	std::cout << "f:		" << (f.toFloat() / 4) << std::endl;
	std::cout << "f:		" << (f / Fixed(4)) << std::endl;
	std::cout << "min(a, b):	" << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b):	" << Fixed::max(a, b) << std::endl;
	std::cout << "min(c, b):	" << Fixed::min(c, b) << std::endl;
	std::cout << "max(c, b):	" << Fixed::max(c, b) << std::endl << std::endl;
	if (a != 0)
		std::cout << "this should not be displayed!" << std::endl;
	if (--a <= c)
		std::cout << "this is true!" << std::endl;
}

void own_div0(void)
{
	// "If you ever do a division by 0,
	// it is acceptable that the program crashes"
	Fixed a(20);
	Fixed b = a / 0;
}

int main(void)
{
	std::cout << "~-~-~-~-~-~-~-~-~  >> ex02 <<  ~-~-~-~-~-~-~-~-~\n"
			  << std::endl;
	subject_tests();
	std::cout << "\n~-~-~-~-~-~-~-~-~  >> own tests <<  ~-~-~-~-~-~-~-~-~\n"
			  << std::endl;
	own_tests();
	// own_div0();
}
