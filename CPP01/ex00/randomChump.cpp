#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie temp;
	temp.setname(name);
	temp.announce();
}