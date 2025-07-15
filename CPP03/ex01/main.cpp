#include "ScavTrap.hpp"

void oldtests(void)
{
	ClapTrap KekTrap("Superkek");
	KekTrap.attack("Afghanistan");
	KekTrap.takeDamage(1);
	KekTrap.beRepaired(69);
	KekTrap.takeDamage(500);
	KekTrap.attack("Talibans");
	KekTrap.beRepaired(69);
}

void newtests(void)
{
	ScavTrap MegTrap("Megakek");
	ScavTrap loltrap("Ultrakek");
	loltrap.guardGate();
	MegTrap.attack("Iran");
	MegTrap.takeDamage(1);
	MegTrap.beRepaired(69);
	MegTrap.takeDamage(50);
	MegTrap.attack("Iran's Fordow nuclear facility");
	MegTrap.beRepaired(69);
}

int main(void)
{
	std::cout << "~-~-~-~-~-~-~-~-~  >> ex01 <<  ~-~-~-~-~-~-~-~-~\n" << std::endl;
	std::cout << "OLDTESTS:" << std::endl;
	oldtests();
	std::cout << "\nNEWTESTS:" << std::endl;
	newtests();
}
