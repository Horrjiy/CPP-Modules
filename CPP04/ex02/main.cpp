#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void subject_tests(void)
{
	std::cout << "\033[0;31mTest 1: subject test\033[0;0m" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j; // should not create a leak
	delete i;
}

void test2(void)
{
	std::cout << "\033[0;31mTest 2: own tests\033[0;0m" << std::endl;
	std::cout << "\033[0;34mPREPARATION:\033[0;0m" << std::endl;
	Animal *herd[6];
	Dog *d = new Dog("BaseDog");
	Cat *c = new Cat("BaseCat");
	d->getBrain()->setIdea(0, "24");
	d->getBrain()->setIdea(1, "42");
	c->getBrain()->setIdea(0, "Sheesh");
	c->getBrain()->setIdea(1, "Shorsh");

	std::cout << "\n\033[0;34mARRAY CONSTRUCTION:\033[0;0m";
	for (int i = 0; i < 6; i++)
	{
		std::cout << std::endl;
		if (i % 2)
			herd[i] = new Dog(*d);
		else
			herd[i] = new Cat(*c);
	}

	std::cout << "\n\n\033[0;34mDEEP COPY PROOF:\033[0;0m" << std::endl;
	delete d;
	delete c;
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		if (i % 2)
		{
			std::cout << dynamic_cast<Dog*>(herd[i])->getBrain()->getIdea(0) << std::endl;
			std::cout << dynamic_cast<Dog*>(herd[i])->getBrain()->getIdea(1) << std::endl;
		}
		else
		{
			std::cout << dynamic_cast<Cat*>(herd[i])->getBrain()->getIdea(0) << std::endl;
			std::cout << dynamic_cast<Cat*>(herd[i])->getBrain()->getIdea(1) << std::endl;
		}
		herd[i]->makeSound();
	}
	
	std::cout << std::endl;

	std::cout << "\033[0;34mARRAY DESTRUCTION:\033[0;0m" << std::endl;
	for (int i = 0; i < 6; i++)
		delete herd[i];
}

int main(void)
{
	std::cout << "~-~-~-~-~-~-~-~-~  >> ex00 <<  ~-~-~-~-~-~-~-~-~\n\n";
	subject_tests();
	std::cout << std::endl;
	test2();
	std::cout << std::endl;
	// Animal bre;
	return (0);
}

