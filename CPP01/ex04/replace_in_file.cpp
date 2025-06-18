#include "replace.hpp"

int replace_in_file(int argc, std::string *args)
{
	/* Argument & file checks */
	if (argc != 4)
		return (std::cerr << "format: 	./replace <filename> <str1> <str2>" << std::endl, 1);
	std::ifstream ifile(args[1]);
	if (!ifile.is_open())
		return (std::cerr << "error: file can't be opened" << std::endl, 2);
	std::ofstream ofile((args[1]) + ".replace");
	if (!ofile.is_open())
		return (std::cerr << "error: file can't be created" << std::endl, 2);

	/* copy file */
	size_t pos;
	size_t oldpos = 0;
	size_t len = args[2].size();
	size_t replen = args[3].size();
	std::stringstream buffer;
	buffer << ifile.rdbuf();
	std::string content = buffer.str();
	while ((pos = content.find(args[2], oldpos)) != std::string::npos)
	{
		content.erase(pos, len);
		content.insert(pos, args[3]);
		oldpos = pos + 1 + replen;
	}
	ofile << content;
	ifile.close();
	ofile.close();
	return (0);
}