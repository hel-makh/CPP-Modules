/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:22:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/07 14:48:46 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const number) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(number);
}

Fixed::Fixed(float const number) {
	std::cout << "Float constructor called" << std::endl;
	this->value = number * (1 << this->fractionalBits);
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(rhs.getRawBits() / (1 << this->fractionalBits));
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw * (1 << this->fractionalBits);
}

int	Fixed::toInt(void) const {
	return (this->getRawBits() / (1 << this->fractionalBits));
}

float	Fixed::toFloat(void) const {
	return ((float)this->getRawBits() / (float)(1 << this->fractionalBits));
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return (o);
}
