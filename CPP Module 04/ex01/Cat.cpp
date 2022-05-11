/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:39:02 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/11 11:42:18 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*************************[ Constructors/Destructors ]*************************/

Cat::Cat(void) {
	std::string	ideas[100];
	
	std::cout << "Cat Default constructor called." << std::endl;
	this->setType("Cat");
	ideas[0] = "";
	ideas[1] = "";
	this->_brain = new Brain(ideas);
}

Cat::Cat(std::string const type) {
	std::string	ideas[100];
	
	std::cout << "Cat Type constructor called." << std::endl;
	this->setType(type);
	ideas[0] = "";
	ideas[1] = "";
	this->_brain = new Brain(ideas);
}

Cat::Cat(Cat const & rhs) {
	std::cout << "Cat Copy constructor called." << std::endl;
	*this = rhs;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called." << std::endl;
	delete this->_brain;
}

/****************************[ Operators overload ]****************************/

Cat &	Cat::operator=(Cat const & rhs) {
	std::cout << "Cat Copy assignment operator called." << std::endl;
	this->setType(rhs.getType());
	this->setBrain(rhs.getBrain());
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

Brain *	Cat::getBrain(void) const {
	return (this->_brain);
}

void	Cat::setBrain(Brain *brain) {
	delete this->_brain;
	this->_brain = new Brain(*brain);
}

void	Cat::makeSound(void) const {
	std::cout << "Meow meow!" << std::endl;
}
