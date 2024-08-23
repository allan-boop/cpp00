#include "PhoneBook.class.hpp"

int main(void) {
	PhoneBook   phoneBook;
	str command;

	while(1) {
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (std::cin.eof()) {
            std::cout << "End of input detected. Exiting..." << std::endl;
            break;
        }
		if (command == "ADD") {
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << "Invalid command." << std::endl;
			std::cout << "Valid commands: ADD, SEARCH, EXIT" << std::endl;
		}
	}
	return 0;
}