#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
public:
	Cat();
	Cat(std::string typestr);
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	~Cat();
	void makeSound(void) const override;
	Brain *getBrain(void);

private:
	Brain *catbrain;
};

#endif /* CAT_HPP */