#include "Zombie.hpp"

Zombie::Zombie() : name("default")
{

}

void Zombie::announce(void)
{
	std::cout << "efejrtg";
}

std::string Zombie::getname(void)
{
	return(this->name);
}