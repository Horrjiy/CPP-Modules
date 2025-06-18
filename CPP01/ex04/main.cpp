#include "replace.hpp"

std::string *convertstring(int argc, char **argv)
{
	std::string *strarr = new std::string[argc];
	for(int i = 0; i < argc; i++)
		strarr[i] = argv[i];
	if (!strarr)
		return (NULL);
	return(strarr);
}

int main(int argc, char **argv)
{
	std::cout << "This is the replace_in_file tester. type 1, 2 or 3 for a premade testcase(), or 0 for your own!" << std::endl;
	std::string str;
	if (!std::getline(std::cin, str))
		return (1);
	str.resize(1);
	if (str == "1")
		test1();
	else if (str == "2")
		test2();
	else if (str == "3")
		test3(); 
	else if (str == "0")
		replace_in_file(argc, convertstring(argc, argv));
	else
		return (std::cerr << "wrong input. program ends." << std::endl, 1);
	std::cout << "program ends." << std::endl;
	return (0);
}
