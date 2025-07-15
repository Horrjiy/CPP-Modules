#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal();
	Animal(std::string typestr);
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal();
	virtual void makeSound(void) const;
	std::string getType(void) const;
protected:
	std::string type;
};

#endif /* ANIMAL_HPP */