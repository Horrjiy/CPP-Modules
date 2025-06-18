#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *temp = new Zombie();
	if (!temp)
		return (NULL);
	(*temp).setname(name);
	return (temp);
}