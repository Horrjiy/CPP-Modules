#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string typestr);
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal &operator=(const WrongAnimal &copy);
	virtual ~WrongAnimal();
	void makeSound(void) const;
	std::string getType(void) const;

protected:
	std::string type;
};

#endif /* WRONGANIMAL_HPP */