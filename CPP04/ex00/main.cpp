#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void subject_tests(void)
{
	// Animal
	std::cout << "\033[0;31mTest 1: Subject Tests\033[0;37m" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;
	std::cout << std::endl;

	// WrongAnimal
	std::cout << "\033[0;31mTest 2: Subject WrongTests\033[0;37m" << std::endl;
	const WrongAnimal *wmeta = new WrongAnimal();
	const WrongAnimal *wi = new WrongCat();
	std::cout << wi->getType() << " " << std::endl;
	wi->makeSound();
	wmeta->makeSound();
	std::cout << std::endl;
	delete wmeta;
	delete wi;
}

void test2(void)
{
	std::cout << "\033[0;31mTest 3: basic stuff\033[0;37m" << std::endl;
	Animal a1;
	Dog d1;
	Cat c1;
	a1.makeSound();
	d1.makeSound();
	c1.makeSound();
	std::cout << std::endl;
}

void test3(void)
{
	std::cout << "\033[0;31mTest 4: Animal pointers\033[0;37m" << std::endl;
	Animal *void_ani = new Animal();
	Animal *dog_ani = new Dog();
	Animal *cat_ani = new Cat();
	Animal *cock = new Dog("Doggystyle");
	Animal *beep(cock); // Copy -> doens't have to be freed

	void_ani->makeSound();
	dog_ani->makeSound();
	cat_ani->makeSound();
	cock->makeSound();
	beep->makeSound();

	std::cout << std::endl;
	delete cock;
	delete void_ani;
	delete dog_ani;
	delete cat_ani;
}

int main(void)
{
	std::cout << "~-~-~-~-~-~-~-~-~  >> ex00 <<  ~-~-~-~-~-~-~-~-~\n\n";
	subject_tests();
	std::cout << std::endl;
	test2();
	std::cout << std::endl;
	test3();
	std::cout << std::endl;
	return(0);
}
