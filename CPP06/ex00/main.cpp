#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if(argc < 2)
		return(std::cerr << "provide an argument!\n", 1);
	ScalaConverter::convert(argv[1]);
}