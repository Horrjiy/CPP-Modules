#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
public:
	Dog();
	Dog(std::string typestr);
	Dog(const Dog &copy);
	Dog &operator=(const Dog &copy);
	~Dog();
	void makeSound(void) const override;
};

#endif /* DOG_HPP */