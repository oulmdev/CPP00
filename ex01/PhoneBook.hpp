/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmoud <moulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 03:07:43 by moulmoud          #+#    #+#             */
/*   Updated: 2023/07/11 05:06:15 by moulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Contact.hpp"

class Phonebook {

	private:
		Contact contacts[8];
		int		index;
	public:
		void addContact(std:: string firstName, std:: string lastName, std:: string nickname, std:: string phoneNumber, std:: string darkestSecret, int index);
		// void searchContact();
		void	printContacts();
		int		getIndex();

};
