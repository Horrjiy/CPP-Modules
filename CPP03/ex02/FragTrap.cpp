#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << this->Name << ": Default FragConstructor called\n";
	this->hitpoints = 100;
	this->energy = 100;
	this->dmg = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << this->Name << ": Name FragConstructor called\n";
	this->hitpoints = 100;
	this->energy = 100;
	this->dmg = 30;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << this->Name << ": Copy FragConstructor called\n";
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << this->Name << ": FragDestructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "Copy assignment FragConstructor" << std::endl;
	this->Name = copy.Name;
	this->hitpoints = copy.hitpoints;
	this->energy = copy.energy;
	this->dmg = copy.dmg;
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	if (!this->hitpoints || !this->energy)
	{
		std::cout << this->Name << " tries to Frag-attack " << target << " but can't!" << std::endl;
		return;
	}
	energy -= 1;
	std::cout << this->Name << " Frag-attacks " << target;
	std::cout << "! - causing " << this->dmg << " damage." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Hi. I display a positive high-fives request on the standard output." << std::endl;
}
