/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:39:02 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/11 17:14:35 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*************************[ Constructors/Destructors ]*************************/

Dog::Dog(void) {
	std::string	ideas[100];
	
	std::cout << "Dog Default constructor called." << std::endl;
	this->setType("Dog");
	for (int i = 0; i < 100; i ++) {
		ideas[i] = "Dog Idea " + std::to_string(i);
	}
	this->_brain = new Brain(ideas);
}

Dog::Dog(std::string const type) {
	std::string	ideas[100];
	
	std::cout << "Dog Type constructor called." << std::endl;
	this->setType(type);
	for (int i = 0; i < 100; i ++) {
		ideas[i] = "Dog Idea " + std::to_string(i);
	}
	this->_brain = new Brain(ideas);
}

Dog::Dog(Dog const & rhs) {
	std::cout << "Dog Copy constructor called." << std::endl;
	*this = rhs;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called." << std::endl;
	delete this->_brain;
}

/****************************[ Operators overload ]****************************/

Dog &	Dog::operator=(Dog const & rhs) {
	std::cout << "Dog Copy assignment operator called." << std::endl;
	this->setType(rhs.getType());
	this->setBrain(rhs.getBrain());
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

Brain *	Dog::getBrain(void) const {
	return (this->_brain);
}

void	Dog::setBrain(Brain *brain) {
	delete this->_brain;
	this->_brain = new Brain(*brain);
}

void	Dog::makeSound(void) const {
	std::cout << "Woof woof!" << std::endl;
}
