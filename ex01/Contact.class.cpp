#include "Contact.class.hpp"

typedef str str;

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

str Contact::getFirstName(void) {
	return this->_firstName;
}

void Contact::setFirstName(str firstName) {
	this->_firstName = firstName;
}

str Contact::getLastName(void) {
	return this->_lastName;
}

void Contact::setLastName(str lastName) {
	this->_lastName = lastName;
}

str Contact::getNickname(void) {
	return this->_nickname;
}

void Contact::setNickname(str nickname) {
	this->_nickname = nickname;
}

str Contact::getPhoneNumber(void) {
	return this->_phoneNumber;
}

void Contact::setPhoneNumber(str phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

str Contact::getDarkestSecret(void) {
	return this->_darkestSecret;
}

void Contact::setDarkestSecret(str darkestSecret) {
	this->_darkestSecret = darkestSecret;
}

void Contact::displayContact(void) {
		std::cout << "Firstname: " << this->_firstName << std::endl;
		std::cout << "Lastname: " << this->_lastName << std::endl;
		std::cout << "Nickname: " << this->_nickname << std::endl;
		std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
		std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

void Contact::displayContactShort(void) {
		if (this->_firstName.length() > 10) {
				std::cout << std::right << this->_firstName.substr(0, 9) << "." << "|";
		} else {
				std::cout << std::setw(10) << std::setfill(' ') << std::right << this->_firstName << "|";
		}
		if (this->_lastName.length() > 10) {
				std::cout << std::right << this->_lastName.substr(0, 9) << "." << "|";
		} else {
				std::cout << std::setw(10) << std::setfill(' ') << std::right << this->_lastName << "|";
		}
		if (this->_nickname.length() > 10) {
				std::cout << std::right << this->_nickname.substr(0, 9) << ".";
		} else {
				std::cout << std::setw(10) << std::setfill(' ') << std::right << this->_nickname;
		}
		std::cout << std::endl;
}
