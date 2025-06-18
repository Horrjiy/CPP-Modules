#include "Zombie.hpp"

int main(int argc, char **argv)
{
	/* argument checks */
	if (argc != 3)
	{
		std::cout << "format:	 ./brainz <name1> <name2>" << std::endl;
		return (1);
	}

	/* zombies */
	randomChump(argv[1]);
	Zombie *newzom = newZombie(argv[2]);
	if (!newzom)
		return (std::cerr << "error: 'new' failed", 1);
	newzom->announce();
	delete newzom;
}