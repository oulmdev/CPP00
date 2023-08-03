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
			return (false);
		}
		std::istringstream iss(inputLine);
		if (!(iss >> result) || result < 1 || result > 8) {
			std::cout << "\033[1;31mError:\033[0m You have to enter a number between 1 and 8, try again." << std::endl;
		}
		else if (result - 1 > this->contactCount && !this->isFull)
		{
			std::cout << "\033[1;31mError:\033[0m You have only " << this->contactCount << " contacts, try again." << std::endl;
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

bool PhoneBook:: isEmpty(std:: string toCheck) {
	if (toCheck.length() == 0)
		return (false);
	for (unsigned long i = 0; i < toCheck.length(); i++) {
		if (!std:: isspace(toCheck[i]))
			return (true);
	}
	return (false);
}

bool PhoneBook:: isNumber(std:: string &toCheck) {
	for (unsigned long i = 0; i < toCheck.length(); i++) {
		if (!std:: isdigit(toCheck[i]))
		{
			return (false);
		}
	}
	return(true);
}

bool PhoneBook:: add() {
	std:: string input[5];
	std:: string fields[5] = {"firs name",
							"last name",
							"nick name",
							"phone number",
							"darkest secret"};
	Contact newContact;
	for (int i = 0; i < 5; i++)
	{
		std:: cout << "Enter " << fields[i] << ": ";
		std:: getline(std:: cin, input[i]);
		if (std:: cin.eof())
			return false;
		if (!this->isEmpty(input[i]))
		{
			std:: cout << "\033[1;31mError:\033[0m " << fields[i] << " cannot be empty." << std:: endl;
			i--;
		}
		if (fields[i] == "phone number")
		{
			if (!this->isNumber(input[i]))
			{
				std:: cout << "\033[1;31mError:\033[0m " << fields[i] << " Should be valid." << std:: endl;
				i--;
			}
		}
	}
	newContact.setFirstName(input[0]);
	newContact.setLastName(input[1]);
	newContact.setNickName(input[2]);
	newContact.setPhoneNumber(input[3]);
	newContact.setDarkestSecret(input[4]);

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
