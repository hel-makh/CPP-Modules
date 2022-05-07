/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:56:02 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/07 17:48:02 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {
}

Point::Point(Point const & rhs) : _x(rhs.getX()), _y(rhs.getY()) {
}

Point::~Point(void) {
}

Point &	Point::operator=(Point const & rhs) {
	if (this != &rhs) {
		this->~Point();
		new (this) Point(rhs);
	}
	return (*this);
}

Fixed	Point::getX(void) const {
	return (this->_x);
}

Fixed	Point::getY(void) const {
	return (this->_y);
}
