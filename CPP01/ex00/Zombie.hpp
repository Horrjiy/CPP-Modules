#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
	Zombie();
	void announce(void);
	std::string getname(void);
	

private:
	std::string name;
};

#endif /* ZOMBIE_HPP */