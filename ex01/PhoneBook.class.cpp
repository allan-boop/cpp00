#include "PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>
#include <algorithm>

typedef std::string str;

int PhoneBook::_contactCount = 0;
int PhoneBook::_contactIndex = 0;

PhoneBook::PhoneBook(void) {
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

// ADD
str PhoneBook::get_and_set_var(str varName) {
	str var;
	str temp;

	while (1) {
		std::cout << "Enter " << varName << ": ";
		std::getline(std::cin, var);
		if (std::cin.eof()) {
            std::cout << "End of input detected. Exiting..." << std::endl;
            return "";
        }
		if (var.length() > 0) {
			std::cin.clear();
			std::cin.sync();
			return var;
		} else {
			std::cout << "Invalid " << varName << ". ";
		}
	}
}

// ADD
void PhoneBook::modifyContact(str firstName, str lastName, str nickname, str phoneNumber, str darkestSecret) {
	if (PhoneBook::_contactCount < 8) {
		this->_contacts[PhoneBook::_contactCount].setFirstName(firstName);
		this->_contacts[PhoneBook::_contactCount].setLastName(lastName);
		this->_contacts[PhoneBook::_contactCount].setNickname(nickname);
		this->_contacts[PhoneBook::_contactCount].setPhoneNumber(phoneNumber);
		this->_contacts[PhoneBook::_contactCount].setDarkestSecret(darkestSecret);
		PhoneBook::_contactCount++;
	} else {
		int i = 0;
		while (i < 7) {
			this->_contacts[i] = this->_contacts[i + 1];
			i++;
		}
		this->_contacts[7].setFirstName(firstName);
		this->_contacts[7].setLastName(lastName);
		this->_contacts[7].setNickname(nickname);
		this->_contacts[7].setPhoneNumber(phoneNumber);
		this->_contacts[7].setDarkestSecret(darkestSecret);
	}
}

// ADD
void PhoneBook::addContact(void) {
	str firstName;
	str lastName;
	str nickname;
	str phoneNumber;
	str darkestSecret;
	firstName = get_and_set_var("first name");
	lastName = get_and_set_var("last name");
	nickname = get_and_set_var("nickname");
	phoneNumber = get_and_set_var("phone number");
	darkestSecret = get_and_set_var("darkest secret");
	this->modifyContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

// SEARCH
void PhoneBook::displayContact(int index) {
	str temp;
	if (index < PhoneBook::_contactCount) {
		this->_contacts[index].displayContact();
	} else {
		std::cout << "Contact not found." << std::endl;
	}
}

// SEARCH
int PhoneBook::displayList(void) {
	int i = 0;

	if ( PhoneBook::_contactCount == 0) {
		std::cout << "No contacts available." << std::endl;
		return 0;
	}
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (i < PhoneBook::_contactCount) {
		std::cout << std::setw(10) << std::setfill(' ') << std::right << i << "|";
		this->_contacts[i].displayContactShort();
		i++;
	}
	return 1;
}

// SEARCH
bool isNumber(const std::string& string) {
	if (string.length() == 0)
		return false;
    for (size_t i = 0; i < string.length(); ++i) {
        if (!isdigit(string[i])) {
            return false;
        }
    }
    return true;
}

// SEARCH
void PhoneBook::searchContact(void) {
	long int	index;
	str			command;
	int			i = 0;

	if (this->displayList() == 0)
		return;
	while (i == 0) {
		std::cout << "Enter index: ";
		std::getline(std::cin, command);
		if (std::cin.eof()) {
			std::cout << "End of input detected. Exiting..." << std::endl;
			return;
		}
		if (!isNumber(command)) {
			std::cout << "Invalid input. Please enter a number." << std::endl;
		}
		else
			i = 1;
	}
    index = atoi(command.c_str());
	this->displayContact(index);
}
