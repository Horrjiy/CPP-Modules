#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
	Zombie();
	~Zombie();
	void announce(void);
	void setname(std::string input);
	
private:
	std::string name;
};

Zombie *zombieHorde(int N, std::string name);
void randomChump(std::string name);

#endif /* ZOMBIE_HPP */