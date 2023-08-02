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
		bool	isEmpty(std:: string toCheck);
		std::	string resizeString(std:: string toResize);
		bool	printContact();
		bool	isNumber(std:: string &toCheck);

		~PhoneBook();

};

#endif
