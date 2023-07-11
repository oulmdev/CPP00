/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmoud <moulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:57:58 by moulmoud          #+#    #+#             */
/*   Updated: 2023/07/11 05:07:41 by moulmoud         ###   ########.fr       */
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

void Phonebook:: printContacts()
{
	for (int i = 0; i < 8 ; i++) {
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
