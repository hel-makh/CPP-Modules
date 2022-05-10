/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:39:02 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/10 17:53:17 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*************************[ Constructors/Destructors ]*************************/

Cat::Cat(void) {
	this->setType("Cat");
	std::cout << "Cat Default constructor called." << std::endl;
	return ;
}

Cat::Cat(std::string type) {
	this->setType(type);
	std::cout << "Cat Type constructor called." << std::endl;
	return ;
}

Cat::Cat(Cat const & rhs) {
	std::cout << "Cat Copy constructor called." << std::endl;
	*this = rhs;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called." << std::endl;
}

/****************************[ Operators overload ]****************************/

Cat &	Cat::operator=(Cat const & rhs) {
	std::cout << "Cat Copy assignment operator called." << std::endl;
	this->setType(rhs.getType());
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

void	Cat::makeSound(void) const {
	std::cout << "Meow meow!" << std::endl;
}
