#include "Zombie.hpp"

int main(int argc, char **argv)
{
	/* argument checks */
	int N;
	if (argc != 3 || ((std::string)argv[1]).size() > 7 || (N = std::atoi(argv[1])) <= 0)
	{
		if (argc != 3)
			std::cout << "format:	 ./moarbrainz <number> <name>" << std::endl;
		else
			std::cout << "enter a number between 1 and 9'999'999" << std::endl;
		return (1);
	}

	/* zombies */
	Zombie *newzom = zombieHorde(N, argv[2]);
	if (!newzom)
		return (std::cerr << "error: 'new' failed", 1);
	for (int i = 0; i < N; i++)
		newzom[i].announce();
	delete[] newzom;
	return (0);
}
