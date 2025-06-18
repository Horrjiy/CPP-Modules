#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string name) : type(name)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::gettype(void)
{
	return(this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
