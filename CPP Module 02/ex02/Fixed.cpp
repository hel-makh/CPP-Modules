/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:22:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/07 16:24:40 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*************************[ Constructors/Destructors ]*************************/

Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const number) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(number);
}

Fixed::Fixed(float const number) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(number * (1 << this->fractionalBits));
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

/****************************[ Operators overload ]****************************/

Fixed &	Fixed::operator=(Fixed const & rhs) {
	this->value = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const & rhs) const {
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const & rhs) const {
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const & rhs) const {
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const & rhs) const {
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const & rhs) const {
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const & rhs) const {
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const & rhs) const {
	Fixed	fixedPoint(this->toFloat() + rhs.toFloat());
	return (fixedPoint);
}

Fixed	Fixed::operator-(Fixed const & rhs) const {
	Fixed	fixedPoint(this->toFloat() - rhs.toFloat());
	return (fixedPoint);
}

Fixed	Fixed::operator*(Fixed const & rhs) const {
	Fixed	fixedPoint(this->toFloat() * rhs.toFloat());
	return (fixedPoint);
}

Fixed	Fixed::operator/(Fixed const & rhs) const {
	Fixed	fixedPoint(this->toFloat() / rhs.toFloat());
	return (fixedPoint);
}

Fixed	Fixed::operator++(void) {
	Fixed	fixedPoint;

	fixedPoint.value = ++this->value;
	return (fixedPoint);
}

Fixed	Fixed::operator++(int) {
	Fixed	fixedPoint;

	fixedPoint.value = this->value++;
	return (fixedPoint);
}

Fixed	Fixed::operator--(void) {
	Fixed	fixedPoint;

	fixedPoint.value = --this->value;
	return (fixedPoint);
}

Fixed	Fixed::operator--(int) {
	Fixed	fixedPoint;

	fixedPoint.value = this->value--;
	return (fixedPoint);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return (o);
}

/*****************************[ Member Functions ]*****************************/

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

Fixed &	Fixed::min(Fixed & fixed1, Fixed & fixed2) {
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed const &	Fixed::min(Fixed const & fixed1, Fixed const & fixed2) {
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed &	Fixed::max(Fixed & fixed1, Fixed & fixed2) {
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed const &	Fixed::max(Fixed const & fixed1, Fixed const & fixed2) {
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}
