#pragma once

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
#include <iostream>
#include <string>
#include <iomanip>

typedef std::string str;

class Contact {
	public:
		Contact(void);
		~Contact(void);

		void	setFirstName(str firstName);
		void	setLastName(str lastName);
		void	setNickname(str nickname);
		void	setPhoneNumber(str phoneNumber);
		void	setDarkestSecret(str login);

		str getFirstName(void);
		str getLastName(void);
		str getNickname(void);
		str getPhoneNumber(void);
		str getDarkestSecret(void);

		void	displayContact(void);
		void	displayContactShort(void);

	private:
		str _firstName;
		str _lastName;
		str _nickname;
		str _phoneNumber;
		str _darkestSecret;
};

#endif