#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
public:
	Weapon();
	Weapon(std::string name);
	~Weapon();
	const std::string &gettype(void);
	void setType(std::string type);

private:
	std::string type;
};

#endif /* WEAPON_HPP */