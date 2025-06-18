#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
	const std::string weaponname = armament->gettype();
	if (weaponname.c_str() || !weaponname.empty())
		std::cout << this->name << " attacks with their " << weaponname << std::endl;
	else
		std::cout << this->name << " attacks with no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &armament)
{
	this->armament = &armament;
}
