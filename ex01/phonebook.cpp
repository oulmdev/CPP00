# include "PhoneBook.hpp"

PhoneBook:: PhoneBook() {
	this->contactCount = 0;
	this->isFull = false;
}

void PhoneBook:: addContact(Contact const &contact) {
	this->contacts[this->contactCount] = contact;
	this->contactCount++;
	if (this->contactCount == 8) {
		this->isFull = true;
		this->contactCount = 0;
	}
}

std::string  PhoneBook:: resizeString(std:: string toResize) {
	if (toResize.length() > 10)
		toResize = toResize.substr(0, 9) + ".";
	if (toResize.length() < 10)
		toResize.resize(10, ' ');
	return (toResize);
}

bool PhoneBook:: printContact() {
	std::string inputLine;
    int result;
	bool	flag;

	flag = true;
	while (flag){
		std::cout << "Enter The index of the contact you want to see: ";
		std::getline(std::cin, inputLine);
		if (std::cin.eof()) {
			std::cout << "Error: EOF" << std::endl;
			return (false);
		}
		std::istringstream iss(inputLine);
		if (!(iss >> result) || result < 1 || result > 8) {
			std::cout << "Error: You have to enter a number between 1 and 8, try again." << std::endl;
		}
		else {
			flag = false;
		}
	}
	std::cout << "First Name: " << this->contacts[result - 1].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contacts[result - 1].getLastName() << std::endl;
	std::cout << "Nick Name: " << this->contacts[result - 1].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->contacts[result - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[result - 1].getDarkestSecret() << std::endl;
	return (true);
}

void PhoneBook:: printTable() {
	if (this->isFull) {
		for (int i = 0; i < 8; i++) {
			std:: cout << i + 1 << "         |" << this->resizeString(this->contacts[i].getFirstName()) << "|" << this->resizeString(this->contacts[i].getLastName()) << "|" << this->resizeString(this->contacts[i].getNickName()) << "|" << std::endl;
		}
	}
	else {
		for (int i = 0; i <= this->contactCount ; i++) {
			std:: cout << i + 1 << "         |" << this->resizeString(this->contacts[i].getFirstName()) << "|" << this->resizeString(this->contacts[i].getLastName()) << "|" << this->resizeString(this->contacts[i].getNickName()) << "|" << std::endl;
		}
	}
}

void PhoneBook:: printContacts() {
	if (this->isFull) {
		for (int i = 0; i < 8; i++) {
			std:: cout << i + 1 << "         |" << this->resizeString(this->contacts[i].getFirstName()) << "|" << this->resizeString(this->contacts[i].getLastName()) << "|" << this->resizeString(this->contacts[i].getNickName()) << "|" << std::endl;
		}
		return ;
	}
	for (int i = 0; i < this->contactCount; i++) {
		std:: cout << i + 1 << "         |" << this->resizeString(this->contacts[i].getFirstName()) << "|" << this->resizeString(this->contacts[i].getLastName()) << "|" << this->resizeString(this->contacts[i].getNickName()) << "|" << std::endl;
	}
}

bool PhoneBook:: add() {
	std:: string firstName;
	std:: string lastName;
	std:: string nickName;
	std:: string phoneNumber;
	std:: string darkestSecret;

	Contact newContact;

	std:: cout << "Enter first name: ";
	std:: getline(std:: cin, firstName);
	if (std:: cin.eof())
		return (false);
	std:: cout << "Enter last name: ";
	std:: getline(std:: cin, lastName);
	if (std:: cin.eof())
		return (false);
	std:: cout << "Enter nickname: ";
	std:: getline(std:: cin, nickName);
	if (std:: cin.eof())
		return (false);
	std:: cout << "Enter phone number: ";
	std:: getline(std:: cin, phoneNumber);
	if (std:: cin.eof())
		return (false);
	std:: cout << "Enter your darkest secret: ";
	std:: getline(std:: cin, darkestSecret);
	if (std:: cin.eof())
		return (false);

	newContact.setDarkestSecret(darkestSecret);
	newContact.setFirstName(firstName);
	newContact.setLastName(lastName);
	newContact.setNickName(nickName);
	newContact.setPhoneNumber(phoneNumber);

	addContact(newContact);
	return (true);
}

void PhoneBook:: runProgram() {

	std:: string command;

	while (1337)
	{
		std:: cout << "PhoneBook: ";
		std:: getline(std:: cin, command);
		if (command == "EXIT" || std:: cin.eof())
			return ;
		else if (command == "ADD") {
			if (!this->add())
				return ;
		}
		else if (command == "SEARCH") {
			this->printContacts();
			if (!this->printContact())
				return ;
		}
		else
			std:: cout << "Invalid command:\nusage: ADD[To add a new contact], SEARCH[display contact table], EXIT[exit the program]" << std:: endl;
	}
}

PhoneBook:: ~PhoneBook() {
	std:: cout << "Thanks for using our PhoneBook" << std:: endl;
}
