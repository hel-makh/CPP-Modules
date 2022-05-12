/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:39:02 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/12 13:33:21 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*************************[ Constructors/Destructors ]*************************/

AAnimal::AAnimal(void) :	_type("Animal") {
	std::cout << "AAnimal Default constructor called." << std::endl;
	return ;
}

AAnimal::AAnimal(std::string const type) :	_type(type) {
	std::cout << "AAnimal Type constructor called." << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const & rhs) {
	std::cout << "AAnimal Copy constructor called." << std::endl;
	*this = rhs;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal Destructor called." << std::endl;
}

/****************************[ Operators overload ]****************************/

AAnimal &	AAnimal::operator=(AAnimal const & rhs) {
	std::cout << "AAnimal Copy assignment operator called." << std::endl;
	this->setType(rhs.getType());
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

std::string	AAnimal::getType(void) const {
	return (this->_type);
}

void	AAnimal::setType(std::string const type) {
	this->_type = type;
}
