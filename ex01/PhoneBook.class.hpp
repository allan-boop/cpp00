#pragma once

#ifndef PHONE_BOOK_CLASS_HPP
# define PHONE_BOOK_CLASS_HPP

# include "Contact.class.hpp"
# include <iostream>

typedef std::string str;

class PhoneBook {
  public:
	PhoneBook(void);
	~PhoneBook(void);

	void  addContact(void);
	void  searchContact(void);

  private:
	void  		displayContact(int index);
	int			displayList(void);
	str			get_and_set_var(str varName);
	void		modifyContact(str firstName, str lastName, str nickname, str phoneNumber, str darkestSecret);
	Contact		_contacts[8];
	static int	_contactCount;
	static int	_contactIndex;
};

#endif