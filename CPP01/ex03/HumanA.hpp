#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon &armament);
	~HumanA();
	void attack(void);

private:
	std::string name;
	Weapon &armament;
};

#endif /* HUMANA_HPP */