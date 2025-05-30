#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "main.hpp"

class PhoneBook
{
public:
	Contact  &getinfo(int index);
	void     setinfo(int ident, Contact con);

private:
	Contact information[8];
};

#endif