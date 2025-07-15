#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
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
	Brain *getBrain(void);

private:
	Brain *dogbrain;
};

#endif /* DOG_HPP */