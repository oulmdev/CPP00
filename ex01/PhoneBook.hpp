# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
# include <sstream>

class PhoneBook{
	private:
		Contact contacts[8];
		int contactCount;
		bool	isFull;
	public:
		PhoneBook();

		void	runProgram();
		bool	add();
		void	addContact(Contact const &contact);
		void	printContacts();
		void	printTable();
		std::	string resizeString(std:: string toResize);
		bool	printContact();

		~PhoneBook();

};

#endif
