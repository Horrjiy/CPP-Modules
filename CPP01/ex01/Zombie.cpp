#include "Zombie.hpp"

Zombie::Zombie() : name("NoName")
{
}

Zombie::~Zombie()
{
	std::cout << this->name;
	std::cout << ": was destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string input)
{
	this->name = input;
}
