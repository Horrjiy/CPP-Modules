#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain constructor" << std::endl; }

Brain::Brain(const Brain &copy)
{
	*this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}

Brain::~Brain() { std::cout << "Brain destructor" << std::endl; }

std::string Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index > 99)
	{
		std::cerr << "U dumb kek can't cause a segfault here, smh!" << std::endl;
		return;
	}
	this->ideas[index] = idea;
	std::cout << "set idea " << index << " to: " << idea << std::endl;
}
