#include "fixed.hpp"

int main(void)
{
	std::cout << "~-~-~-~-~-~-~-~-~  >> ex00 <<  ~-~-~-~-~-~-~-~-~\n" << std::endl;

	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
