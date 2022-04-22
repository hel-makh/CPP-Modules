/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:18:16 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/22 03:10:45 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int	ft_stoi(std::string str) {
	if (str.length() > 1 || str[0] < '0' || str[0] > '9')
		return (-1);
	return (str[0] - '0');
}

static void	printWidth(std::string str, unsigned long width) {
	unsigned long	i;

	if (width == 0 || str.length() <= width)
	{
		std::cout << std::setw(width) << str;
		return ;
	}
	i = 0;
	while (str[i])
	{
		if (i == width - 1)
		{
			std::cout << ".";
			break ;
		}
		std::cout << str[i];
		i ++;
	}
}

static void	displayContacts(PhoneBook phoneBook) {
	Contact		contact;
	std::string	contactIndex;
	int			contactIndex2;
	int			i;

	if (phoneBook.get_contactsSize() == 0)
		return ;
	
	printWidth("Index", 10);
	std::cout << " | ";
	printWidth("First Name", 10);
	std::cout << " | ";
	printWidth("Last Name", 10);
	std::cout << " | ";
	printWidth("NickName", 10);
	std::cout << std::endl << "-------------------------------------------------" << std::endl;

	i = 0;
	while (phoneBook.getContact(contact, i))
	{
		std::cout << std::setw(10) << i + 1;
		std::cout << " | ";
		printWidth(contact.get_firstName(), 10);
		std::cout << " | ";
		printWidth(contact.get_lastName(), 10);
		std::cout << " | ";
		printWidth(contact.get_nickName(), 10);
		std::cout << std::endl << "-------------------------------------------------" << std::endl;
		i ++;
	}

	contactIndex2 = -1;
	while (contactIndex2 == -1)
	{
		std::cout << "-> Insert contact index: ";
		if (!std::getline(std::cin, contactIndex))
			return ;
		contactIndex2 = ft_stoi(contactIndex);
		if (contactIndex2 == -1)
			std::cout << "Invalid input, try again." << std::endl;
	}

	if (!phoneBook.getContact(contact, contactIndex2 - 1))
	{
		std::cerr << "Error: Counldn't find this contact." << std::endl;
		return ;
	}
	
	std::cout << "Informations of contact " << contactIndex2 << ":" << std::endl;
	std::cout << "\tFirst Name: " << contact.get_firstName() << std::endl;
	std::cout << "\tLast Name: " << contact.get_lastName() << std::endl;
	std::cout << "\tNickName: " << contact.get_nickName() << std::endl;
}

static void	addContact(PhoneBook *phoneBook) {
	Contact		contact;
	std::string contactInfo;
	
	std::cout << "\tFirst Name: ";
	if (!std::getline(std::cin, contactInfo))
		return ;
	contact.set_firstName(contactInfo);

	std::cout << "\tLast Name: ";
	if (!std::getline(std::cin, contactInfo))
		return ;
	contact.set_lastName(contactInfo);
	
	std::cout << "\tNickName: ";
	if (!std::getline(std::cin, contactInfo))
		return ;
	contact.set_nickName(contactInfo);
	
	std::cout << "\tPhone Number: ";
	if (!std::getline(std::cin, contactInfo))
		return ;
	contact.set_phoneNumber(contactInfo);
	
	std::cout << "\tDarkest Secret: ";
	if (!std::getline(std::cin, contactInfo))
		return ;
	contact.set_darkestSecrect(contactInfo);

	if (contact.get_firstName().empty()
		|| contact.get_lastName().empty()
		|| contact.get_nickName().empty()
		|| contact.get_phoneNumber().empty()
		|| contact.get_darkestSecrect().empty())
	{
		std::cerr << "Couldn't add contact: Contact can't have an empty field." << std::endl;
		return ;
	}
	
	phoneBook->addContact(contact);
	std::cout << "Contact added successfully." << std::endl;
}

int	main(void) {
	PhoneBook	phoneBook;
	std::string command;

	while (command.compare("EXIT") != 0)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, command))
			break ;
		if (command.compare("ADD") == 0)
			addContact(&phoneBook);
		else if (command.compare("SEARCH") == 0)
			displayContacts(phoneBook);
		else if (command.compare("EXIT") != 0
			&& command.compare("") != 0)
			std::cerr << "Error: Command not found." << std::endl;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return (0);
}
