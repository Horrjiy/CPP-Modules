#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::cout << "\n >> HARL TESTER: <<\n";
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("gibberish");
	std::cout << "\n >> Now your own input: <<\n";
	std::string str;
	if (!std::getline(std::cin, str))
		return (1);
	harl.complain(str);

}