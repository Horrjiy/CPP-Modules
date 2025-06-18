#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ident[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for(int i = 0; i < 4; i++)
		if(level == levels[i])
			{
				(this->*ident[i])();
				return;
			}
	std::cerr << "couldn't find level <" << level << ">" << std::endl; 
}

void Harl::debug(void)
{
	std::cout <<  "I love having extra human meat for my 7XL-special-ketchup-human burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout <<  "I cannot believe adding extra human costs more money. You didn't put enough humans in my burger!" << std::endl;
}

void Harl::warning(void)
{
	std::cout <<  "I think I deserve to have some extra humans for free." << std::endl;
}

void Harl::error(void)
{
	std::cout <<  "This is unacceptable! I want to speak to the slave holder now." << std::endl;
}
