#include "main.hpp"

Contact &PhoneBook::getinfo(int index)
{
	return(this->information[index]);
}

void     PhoneBook::setinfo(int ident, Contact con)
{
	this->information[ident] = con;
}
