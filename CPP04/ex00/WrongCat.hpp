#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(std::string typestr);
	WrongCat(const WrongCat &copy);
	WrongCat &operator=(const WrongCat &copy);
	~WrongCat();
	void makeSound(void) const;
};

#endif /* WRONGCAT_HPP */