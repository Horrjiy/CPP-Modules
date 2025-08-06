#include "Serializer.hpp"

int main(void)
{
	Data stuff;
	stuff.i = -3;
	stuff.x = 69.9;

	std::cout << "Initial Data:	" << &stuff << std::endl;
	uintptr_t xptr = Serializer::serialize(&stuff);
	std::cout << "uintptr_t:	" << xptr << std::endl;
	Data *result = Serializer::deserialize(xptr);
	std::cout << "result Data:	" << result << std::endl;

	if(&stuff == result)
		std::cout << "the pointers are the same!" << std::endl;
	else
		std::cout << "Error: the pointers are not the same!" << std::endl;
}