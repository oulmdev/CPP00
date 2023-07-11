/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmoud <moulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:57:58 by moulmoud          #+#    #+#             */
/*   Updated: 2023/07/11 19:03:47 by moulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "PhoneBook.hpp"

void Phonebook::addContact(std:: string firstName, std:: string lastName, std:: string nickname, std:: string phoneNumber, std:: string darkestSecret, int index)
{
	contacts[index].setFirstName(firstName);
	contacts[index].setLastName(lastName);
	contacts[index].setNickname(nickname);
	contacts[index].setPhoneNumber(phoneNumber);
	contacts[index].setDarkestSecret(darkestSecret);
	this->index = index + 1;
}

std:: string print(std:: string str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
	else
		str.resize(10, ' ');
	return (str);
}

void Phonebook:: printContacts(int isFull)
{
	for (int i = 0; i < isFull ; i++) {
		std::cout << i + 1 << "         " << "|";
		std::cout << print(contacts[i].getFirstName()) << "|";
		std::cout << print(contacts[i].getLastName()) << "|";
		std::cout << print(contacts[i].getNickname()) << "|";
		std::cout << print(contacts[i].getPhoneNumber()) << "|";
		std::cout << print(contacts[i].getDarkestSecret()) << std::endl;
	}
}

int Phonebook::getIndex()
{
	return (this->index);
}

void Phonebook:: printContact(int index) {
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
