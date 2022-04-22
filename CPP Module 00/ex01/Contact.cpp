/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:03:01 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/20 22:34:49 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_firstName(void) const {
    return (this->firstName);
}

std::string Contact::get_lastName(void) const {
    return (this->lastName);
}

std::string Contact::get_nickName(void) const {
    return (this->nickName);
}

std::string Contact::get_phoneNumber(void) const {
    return (this->phoneNumber);
}

std::string Contact::get_darkestSecrect(void) const {
    return (this->darkestSecrect);
}

void Contact::set_firstName(std::string str) {
    this->firstName = str;
}

void Contact::set_lastName(std::string str) {
    this->lastName = str;
}

void Contact::set_nickName(std::string str) {
    this->nickName = str;
}

void Contact::set_phoneNumber(std::string str) {
    this->phoneNumber = str;
}

void Contact::set_darkestSecrect(std::string str) {
    this->darkestSecrect = str;
}
