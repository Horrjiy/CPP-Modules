#include "main.hpp"

int Contact::getindex(void)
{
	return (this->index);
}

std::string Contact::getfname(void)
{
	return (this->fname);
}

std::string Contact::getlname(void)
{
	return (this->lname);
}

std::string Contact::getphonenum(void)
{
	return (this->phonenum);
}

std::string Contact::getnick(void)
{
	return (this->nick);
}

std::string Contact::getsecret(void)
{
	return (this->secret);
}

void Contact::setindex(int num)
{
	this->index = num;
}

void Contact::setcontact(void)
{
	std::cout << "first name: ";
	if (!std::getline(std::cin, this->fname))
		exit(1);
	std::cout << "last name: ";
	if (!std::getline(std::cin, this->lname))
		exit(1);
	std::cout << "nickname: ";
	if (!std::getline(std::cin, this->nick))
		exit(1);
	std::cout << "phone number: ";
	if (!std::getline(std::cin, this->phonenum))
		exit(1);
	std::cout << "darkest secret: ";
	if (!std::getline(std::cin, this->secret))
		exit(1);
}