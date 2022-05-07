/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:11:22 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/07 20:28:45 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

static int	getBigFixedIndex(Fixed const *n, int size) {
	int	BigFixedIndex;

	BigFixedIndex = 0;
	for (int i = 0; i < size; i ++) {
		if (n[i] < n[BigFixedIndex])
			BigFixedIndex = i;
	}
	return (BigFixedIndex);
}

static Fixed	calculateArea(Point const a, Point const b, Point const c) {
	Fixed	Area;
	Fixed	trapAreas[3];
	int		BigFixedIndex;
	
	// trapAreas[0] = ((a.getY() + b.getY()) * (b.getX() - a.getX())) / Fixed(2.0f);
	// trapAreas[1] = ((a.getY() + c.getY()) * (c.getX() - a.getX())) / Fixed(2.0f);
	// trapAreas[2] = ((b.getY() + c.getY()) * (c.getX() - b.getX())) / Fixed(2.0f);
	
	trapAreas[0] = ((a.getY() + b.getY()) * (Fixed::max(a.getX(), b.getX()) - Fixed::min(a.getX(), b.getX()))) / Fixed(2.0f);
	trapAreas[1] = ((a.getY() + c.getY()) * (Fixed::max(a.getX(), c.getX()) - Fixed::min(a.getX(), c.getX()))) / Fixed(2.0f);
	trapAreas[2] = ((b.getY() + c.getY()) * (Fixed::max(b.getX(), c.getX()) - Fixed::min(b.getX(), c.getX()))) / Fixed(2.0f);

	BigFixedIndex = getBigFixedIndex(trapAreas, 3);
	Area = trapAreas[BigFixedIndex] * Fixed(-1.0f);
	
	for (int i = 0; i < 3; i ++) {
		if (i != BigFixedIndex)
			Area = Area + trapAreas[i];
	}

	// Area = trapAreas[0] + trapAreas[1] - trapAreas[2];

	std::cout << "Area: " << Area.toFloat() << std::endl;
	return (Area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	triangleArea;
	Fixed	triangleArea1;
	Fixed	triangleArea2;
	Fixed	triangleArea3;

	triangleArea = calculateArea(a, b, c);
	triangleArea1 = calculateArea(point, a, b);
	triangleArea2 = calculateArea(point, a, c);
	triangleArea3 = calculateArea(point, b, c);

	std::cout << "triangleArea: " << triangleArea << std::endl;
	std::cout << "Total triangleArea: " << triangleArea1 + triangleArea2 + triangleArea3 << std::endl;

	if (triangleArea == triangleArea1 + triangleArea2 + triangleArea3)
		return (true);
	
	return (false);
}
