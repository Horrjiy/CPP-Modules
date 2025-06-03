#include "main.hpp"

void add(PhoneBook *book)
{
	Contact newcon;
	newcon.setcontact();
	if (newcon.getfname().empty() || newcon.getlname().empty() ||
		newcon.getnick().empty() || newcon.getphonenum().empty() || newcon.getsecret().empty())
		return (std::cout << "Contact can't have empty fields" << std::endl, (void)0);
	newcon.setindex(1);
	for (int i = 7; i >= 0; i--)
	{
		if (i != 7)
		{
			book->setinfo(i + 1, book->getinfo(i));
			if (book->getinfo(i + 1).getindex() != 0)
				book->getinfo(i + 1).setindex(book->getinfo(i + 1).getindex() + 1);
		}
		else
			book->setinfo(i, Contact());
	}
	book->setinfo(0, newcon);
}

std::string adapt(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
		return (str);
	}
	else if (str.length() < 10)
	{
		int spaces = 10 - str.length();
		return (std::string(spaces, ' ') + str);
	}
	return (str);
}

void print_line(int index, std::string fname, std::string lname, std::string nick)
{
	std::cout << "         " << index << "|";
	std::cout << adapt(fname) << "|";
	std::cout << adapt(lname) << "|";
	std::cout << adapt(nick) << std::endl;
}

void search(Contact *information)
{
	/* display */
	if (information[0].getindex() == 0)
		return (std::cout << "no contacts yet!" << std::endl, (void)0);
	for (int i = 0; i < 8; i++)
		if (information[i].getindex() != 0)
			print_line(i + 1, information[i].getfname(), information[i].getlname(), information[i].getnick());

	/* search */
	std::string str;
	std::cout << "enter index of a contact (1-8)" << std::endl;
	if (!std::getline(std::cin, str))
		exit(1);
	int i = std::atoi(str.c_str());
	if (i < 1 || i > 8 || information[i - 1].getindex() == 0)
		return (std::cout << "invalid index!" << std::endl, (void)0);
	std::cout << "first name:		" << information[i - 1].getfname() << std::endl;
	std::cout << "last name:		" << information[i - 1].getlname() << std::endl;
	std::cout << "nickname:			" << information[i - 1].getnick() << std::endl;
	std::cout << "phone number:		" << information[i - 1].getphonenum() << std::endl;
	std::cout << "darkest secret:	" << information[i - 1].getsecret() << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	PhoneBook book;
	for (int i = 0; i < 8; i++)
		book.getinfo(i).setindex(0);
	while (1)
	{
		std::cout << "enter ADD, SEARCH or EXIT" << std::endl;
		std::string str;
		if (!std::getline(std::cin, str))
			exit(1);
		if (str == "EXIT")
			exit(0);
		else if (str == "ADD")
			add(&book);
		else if (str == "SEARCH")
			search(&book.getinfo(0));
	}
}
