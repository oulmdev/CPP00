/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmoud <moulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 03:02:42 by moulmoud          #+#    #+#             */
/*   Updated: 2023/07/11 04:02:19 by moulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "PhoneBook.hpp"

int main()
{
	int			index;
	Phonebook	phonebook;
	std::string	command;

	index = 0;
	while (1)
	{
		if (index == 8)
			index = 0;
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
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
			phonebook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret, index);
			index++;
		}
		else if (command == "SEARCH")
		{
			std::cout << "SEARCH" << std::endl;
			phonebook.printContacts();
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
}
