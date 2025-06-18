#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB();
	void attack(void);
	void setWeapon(Weapon &armament);

private:
	std::string name;
	Weapon *armament;
};

#endif /* HUMANB_HPP */