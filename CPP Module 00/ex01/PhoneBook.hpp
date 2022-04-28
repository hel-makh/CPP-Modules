/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:25:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/28 05:02:21 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctype.h>
#include <limits>
#include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
	public:
		PhoneBook(void);
		void	addContact(Contact contact);
		bool	getContact(Contact &contact, int index) const;
		int		get_contactsSize(void) const;
		int		get_contactsIndex(void) const;
	private:
		Contact	contacts[MAX_CONTACTS];
		int		contactsSize;
		int		contactsIndex;
};

#endif