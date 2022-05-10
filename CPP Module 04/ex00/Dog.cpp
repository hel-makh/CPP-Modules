/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:39:02 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/10 17:53:09 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*************************[ Constructors/Destructors ]*************************/

Dog::Dog(void) {
	this->setType("Dog");
	std::cout << "Dog Default constructor called." << std::endl;
	return ;
}

Dog::Dog(std::string type) {
	this->setType(type);
	std::cout << "Dog Type constructor called." << std::endl;
	return ;
}

Dog::Dog(Dog const & rhs) {
	std::cout << "Dog Copy constructor called." << std::endl;
	*this = rhs;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called." << std::endl;
}

/****************************[ Operators overload ]****************************/

Dog &	Dog::operator=(Dog const & rhs) {
	std::cout << "Dog Copy assignment operator called." << std::endl;
	this->setType(rhs.getType());
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

void	Dog::makeSound(void) const {
	std::cout << "Woof woof!" << std::endl;
}
