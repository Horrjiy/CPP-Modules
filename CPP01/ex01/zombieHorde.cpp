#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombs = new Zombie[N];
	if(!zombs)
		return(NULL);
	for (int i = 0; i < N; i++)
		zombs[i].setname(name);
	return (zombs);
}
