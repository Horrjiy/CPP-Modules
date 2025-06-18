#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &armament) : name(name), armament(armament)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << armament.gettype() << std::endl;
}