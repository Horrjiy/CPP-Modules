#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "~-~-~-~-~-~-~-~-~  >> ex00 <<  ~-~-~-~-~-~-~-~-~\n" << std::endl;
	ClapTrap KekTrap("Superkek");
	KekTrap.attack("Iran");
	KekTrap.takeDamage(1);
	KekTrap.beRepaired(69);
	KekTrap.takeDamage(50);
	KekTrap.attack("Afghanistan");
	KekTrap.beRepaired(69);
}
