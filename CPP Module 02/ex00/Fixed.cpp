/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:04:57 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/06 20:37:19 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(copy.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
	return (this->value >> this->fractionalBits);
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw << this->fractionalBits;
}
