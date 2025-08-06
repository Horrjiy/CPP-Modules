#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <regex>
#include <stdexcept>

class ScalaConverter
{
public:
	ScalaConverter() = delete;
	ScalaConverter(const ScalaConverter &copy) = delete;
	ScalaConverter &operator=(const ScalaConverter &copy);
	~ScalaConverter() = delete;

	static void convert(const std::string input);
};

#endif /* SCALARCONVERTER_HPP */