/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:39:02 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/10 17:50:34 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*************************[ Constructors/Destructors ]*************************/

Animal::Animal(void) :	_type("Animal") {
	std::cout << "Animal Default constructor called." << std::endl;
	return ;
}

Animal::Animal(std::string type) :	_type(type) {
	std::cout << "Animal Type constructor called." << std::endl;
	return ;
}

Animal::Animal(Animal const & rhs) {
	std::cout << "Animal Copy constructor called." << std::endl;
	*this = rhs;
}

Animal::~Animal(void) {
	std::cout << "Animal Destructor called." << std::endl;
}

/****************************[ Operators overload ]****************************/

Animal &	Animal::operator=(Animal const & rhs) {
	std::cout << "Animal Copy assignment operator called." << std::endl;
	this->setType(rhs.getType());
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

std::string	Animal::getType(void) const {
	return (this->_type);
}

void	Animal::setType(std::string type) {
	this->_type = type;
}

void	Animal::makeSound(void) const {
	std::cout << "Animal has no sound." << std::endl;
}
