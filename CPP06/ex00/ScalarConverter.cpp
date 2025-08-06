#include "ScalarConverter.hpp"

// ~-~-~-~-~-~-~-~-~ Constructors ~-~-~-~-~-~-~-~-~ //

ScalaConverter &ScalaConverter::operator=(const ScalaConverter &copy)
{
	(void)copy;
	return (*this);
}

// ~-~-~-~-~-~-~-~-~ Functions ~-~-~-~-~-~-~-~-~ //

static void convExtra(std::string input)
{
	if (input == "+inf" || input == "-inf" || input == "nan" || input == "+inff" || input == "-inff" || input == "nanf")
	{
		std::cout << "char:	" << "impossible" << std::endl;
		std::cout << "int:	" << "impossible" << std::endl;
		std::cout << "float:	" << input + "f" << std::endl;
		std::cout << "double:	" << input << std::endl;
	}
	else
		std::cerr << "Error: input does not match any type" << std::endl;
}

static void convChar(std::string input)
{
	if (input[0] == '\'' && input[2] == '\'')
	{
		input.erase(2, 1);
		input.erase(0, 1);
	}
	char c = input[0];
	if (!std::isprint(c))
		std::cout << "char: " << "non printable\n";
	else
		std::cout << "char:	" << c << std::endl;
	std::cout << "int:	" << static_cast<int>(c) << std::endl;
	std::cout << "float:	" << static_cast<float>(c) << std::endl;
	std::cout << "double:	" << static_cast<double>(c) << std::endl;
}

static void convInt(std::string input)
{
	double c;
	try 
		{ c = std::stoi(input); }
	catch (std::exception &e)
		{ std::cout << "int overflow!\n"; 
			return; }
	std::cout << "int:	" << c << std::endl;
	if (c <= 32 || c >= 127)
		std::cout << "char:	" << "non-printable" << std::endl;
	else
		std::cout << "char:	" << static_cast<char>(c) << std::endl;
	std::cout << "float:	" << static_cast<float>(c) << std::endl;
	std::cout << "double:	" << static_cast<double>(c) << std::endl;
}

static void convFl(std::string input)
{
	double c;
	try 
		{ c = std::stof(input); }
	catch (std::exception &e)
		{ std::cout << "float overflow!\n"; 
			return; }
	std::cout << "float:	" << c << std::endl;
	input.erase(input.find('f'), 1);
	if (c <= 32 || c >= 127)
		std::cout << "char:	" << "non-printable" << std::endl;
	else
		std::cout << "char:	" << static_cast<char>(c) << std::endl;
	std::cout << "int:	" << static_cast<int>(c) << std::endl;
	std::cout << "double:	" << static_cast<double>(c) << std::endl;
}

static void convDb(std::string input)
{
	double c;
	try 
		{ c = std::stod(input); }
	catch (std::exception &e)
		{ std::cout << "double overflow!\n"; 
			return; }

	std::cout << "double:	" << c << std::endl;
	if (c <= 32 || c >= 127)
		std::cout << "char:	" << "non-printable" << std::endl;
	else
		std::cout << "char:	" << static_cast<char>(c) << std::endl;
	std::cout << "int:	" << static_cast<int>(c) << std::endl;
	std::cout << "float:	" << static_cast<float>(c) << std::endl;
}

void ScalaConverter::convert(std::string input)
{
	if (std::regex_match(input, std::regex("^(\\-|\\+)?\\d+$")))
		return (convInt(input));
	else if (std::regex_match(input, std::regex("^('.'|.)$")))
		return (convChar(input));
	else if (std::regex_match(input, std::regex("^(\\-|\\+)?\\d+\\.\\d+f$")))
		return (convFl(input));
	else if (std::regex_match(input, std::regex("^(\\-|\\+)?\\d+\\.\\d+$")))
		return (convDb(input));
	else
		return (convExtra(input));
}
