/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:29:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/20 21:23:14 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact {
	public:
		std::string get_firstName(void) const;
		std::string get_lastName(void) const;
		std::string get_nickName(void) const;
		std::string get_phoneNumber(void) const;
		std::string get_darkestSecrect(void) const;
		void set_firstName(std::string str);
		void set_lastName(std::string str);
		void set_nickName(std::string str);
		void set_phoneNumber(std::string str);
		void set_darkestSecrect(std::string str);
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecrect;
};

#endif