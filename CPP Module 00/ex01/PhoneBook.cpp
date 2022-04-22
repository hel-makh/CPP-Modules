/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:00:57 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/21 02:37:54 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : contactsSize(0), contactsIndex(0) {}

void	PhoneBook::addContact(Contact contact) {
	if (this->contactsIndex >= MAX_CONTACTS)
		this->contactsIndex = 0;
	this->contacts[this->contactsIndex] = contact;
	this->contactsIndex ++;
	if (this->contactsSize < MAX_CONTACTS)
		this->contactsSize ++;
}

bool	PhoneBook::getContact(Contact &contact, int index) const {
	if (this->contactsSize == 0 || index < 0 || index >= this->contactsSize)
		return (false);
	contact = this->contacts[index];
	return (true);
}

int	PhoneBook::get_contactsSize(void) const {
	return (this->contactsSize);
}

int	PhoneBook::get_contactsIndex(void) const {
	return (this->contactsIndex);
}
