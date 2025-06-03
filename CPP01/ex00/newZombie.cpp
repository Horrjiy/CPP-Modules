#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	new Zombie(name);
}