/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:48:13 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/28 15:53:22 by mpoplow          ###   ########.fr       */
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
	for (int i = 7; i >= 0; i--)
	{
		if (i != 7)
			book->information[i + 1] = book->information[i];
		else
			book->information[i] = NULL;
			
	}
	book->information[0] = newcon;
}

void search(PhoneBook *book)
{
	(void)book;
}

int main(void)
{
	PhoneBook book;
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
			search(&book);
	}
}

// getline benutzen statt cin