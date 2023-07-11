/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmoud <moulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 03:02:42 by moulmoud          #+#    #+#             */
/*   Updated: 2023/07/11 19:00:35 by moulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "PhoneBook.hpp"

void	addNewContact(Phonebook *phonebook, int index) {
	std:: string firstName;
	std:: string lastName;
	std:: string nickname;
	std:: string phoneNumber;
	std:: string darkestSecret;
	std:: cout << "Enter first name: ";
	std:: getline(std::cin, firstName);
	std:: cout << "Enter last name: ";
	std:: getline(std::cin, lastName);
	std:: cout << "Enter nickname: ";
	std:: getline(std::cin, nickname);
	std:: cout << "Enter phone number: ";
	std:: getline(std::cin, phoneNumber);
	std:: cout << "Enter darkest secret: ";
	std:: getline(std::cin, darkestSecret);
	phonebook->addContact(firstName, lastName, nickname, phoneNumber,
		darkestSecret, index);
}

void	searchCommand(Phonebook *phonebook, int isFull) {
	std::string	command;
	std::cout << "SEARCH" << std::endl;
	phonebook->printContacts(isFull);
	std::cout << "Enter index: ";
	std::getline(std::cin, command);
	if (command.length() == 1 && command[0] >= '1' && command[0] <= '8'
		&& ((command[0] - '0') - 1 < isFull))
		phonebook->printContact((command[0] - '0') - 1);
	else
		std::cout << "Invalid index" << std::endl;
}

int main() {
	int			index;
	int			isFull;
	Phonebook	phonebook;
	std::string	command;

	isFull = 0;
	index = 0;
	while (1)
	{
		if (index == 8)
		{
			isFull = 8;
			index = 0;
		}
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			return (0);
		else if (command == "ADD")
		{
			addNewContact(&phonebook, index++);
			isFull++;
		}
		else if (command == "SEARCH")
			searchCommand(&phonebook, isFull);
		else
			std::cout << "Invalid command" << std::endl;
	}
}
