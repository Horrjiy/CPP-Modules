#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << this->Name << ": Default ScavConstructor called\n";
	this->hitpoints = 100;
	this->energy = 50;
	this->dmg = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << this->Name << ": Name ScavConstructor called\n";
	this->hitpoints = 100;
	this->energy = 50;
	this->dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << this->Name << ": Copy ScavConstructor called\n";
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->Name << ": ScavDestructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "Copy assignment ScavConstructor" << std::endl;
	this->Name = copy.Name;
	this->hitpoints = copy.hitpoints;
	this->energy = copy.energy;
	this->dmg = copy.dmg;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->hitpoints || !this->energy)
	{
		std::cout << this->Name << " tries to scav-attack " << target << " but can't!" << std::endl;
		return;
	}
	energy -= 1;
	std::cout << this->Name << " scav-attacks " << target;
	std::cout << "! - causing " << this->dmg << " damage." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->Name << " guard gate mode" << std::endl;
}
