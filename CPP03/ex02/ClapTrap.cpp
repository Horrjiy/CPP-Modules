#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << this->Name << ": Default ClapConstructor called\n";
}

ClapTrap::ClapTrap(std::string name) : Name(name)
{
	std::cout << this->Name << ": Name ClapConstructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << this->Name << ": Copy ClapConstructor called\n";
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->Name << ": ClapDestructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment ClapConstructor" << std::endl;
	this->Name = copy.Name;
	this->hitpoints = copy.hitpoints;
	this->energy = copy.energy;
	this->dmg = copy.dmg;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->hitpoints || !this->energy)
	{
		std::cout << this->Name << " tries to attack " << target << " but can't!" << std::endl;
		return;
	}
	energy -= 1;
	std::cout << this->Name << " attacks " << target;
	std::cout << "! - causing " << this->dmg << " damage." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitpoints >= amount)
		this->hitpoints = hitpoints - amount;
	else
		hitpoints = 0;
	std::cout << this->Name << " takes damage: " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitpoints || !this->energy)
	{
		std::cout << this->Name << " can't repair" << std::endl;
		return;
	}
	energy -= 1;
	hitpoints += amount;
	std::cout << this->Name << " repairs: " << amount << std::endl;
	return;
}
