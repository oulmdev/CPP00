/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmoud <moulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:03:33 by moulmoud          #+#    #+#             */
/*   Updated: 2023/07/11 18:23:44 by moulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

class Contact {
	private:
		std:: string firstName;
		std:: string lastName;
		std:: string nickname;
		std:: string phoneNumber;
		std:: string darkestSecret;
	public:
		void setFirstName(std:: string firstName);
		void setLastName(std:: string lastName);
		void setNickname(std:: string nickname);
		void setPhoneNumber(std:: string phoneNumber);
		void setDarkestSecret(std:: string darkestSecret);
		std:: string getFirstName();
		std:: string getLastName();
		std:: string getNickname();
		std:: string getPhoneNumber();
		std:: string getDarkestSecret();
		
};
