/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:48:13 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/29 18:31:28 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void add(PhoneBook *book)
{
	Contact newcon;
	std::cout << "first name: ";
	std::getline(std::cin, newcon.fname);
	std::cout << "last name: ";
	std::getline(std::cin, newcon.lname);
	std::cout << "nickname: ";
	std::getline(std::cin, newcon.nick);
	std::cout << "phone number: ";
	std::getline(std::cin, newcon.phonenum);
	std::cout << "darkest secret: ";
	std::getline(std::cin, newcon.secret);
	if (newcon.fname.empty() || newcon.lname.empty() ||
		newcon.nick.empty() || newcon.phonenum.empty() || newcon.secret.empty())
		return (std::cout << "Contact can't have empty fields" << std::endl, (void)0);
	newcon.index = 1;
	for (int i = 7; i >= 0; i--)
	{
		if (i != 7)
		{
			book->information[i + 1] = book->information[i];
			if (book->information[i + 1].index != 0)
				book->information[i + 1].index += 1;
		}
		else
			book->information[i] = Contact();
	}
	book->information[0] = newcon;
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
	if (information[0].index == 0)
		return (std::cout << "no contacts yet!" << std::endl, (void)0);
	for (int i = 0; i < 8; i++)
		if (information[i].index != 0)
			print_line(i + 1, information[i].fname, information[i].lname, information[i].nick);

	/* search */
	std::string str;
	std::cout << "enter index of a contact (1-8)" << std::endl;
	std::getline(std::cin, str);
	int i = std::atoi(str.c_str());
	if (i < 1 || i > 8 || information[i - 1].index == 0)
		return (std::cout << "invalid index!" << std::endl, (void)0);
	std::cout << "first name:   " << information[i - 1].fname << std::endl;
	std::cout << "last name:    " << information[i - 1].lname << std::endl;
	std::cout << "nickname:     " << information[i - 1].nick << std::endl;
	std::cout << "phone number: " << information[i - 1].phonenum << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	PhoneBook book;
	for (int i = 0; i < 8; i++)
		book.information[i].index = 0;
	while (1)
	{
		std::cout << "enter ADD, SEARCH or EXIT" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		if (str == "EXIT")
			return (1);
		else if (str == "ADD")
			add(&book);
		else if (str == "SEARCH")
			search(book.information);
	}
}
