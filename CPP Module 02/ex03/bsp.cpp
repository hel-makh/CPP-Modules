/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:11:22 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/07 23:40:08 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

static bool	hasPoint(Point * Points, int size, Point Point) {
	for (int i = 0; i < size; i ++) {
		if (Points[i].getX() == Point.getX()
			&& Points[i].getY() == Point.getY())
			return (true);
	}
	return (false);
}

static Point *	sortPoints(Point const a, Point const b, Point const c) {
	Point	*Points;
	Point	bigPoint;
	
	Points = new Point[3];
	bigPoint = a;
	for (int i = 0; i < 3; i ++) {
		if (a.getY() > bigPoint.getY() && !hasPoint(Points, 3, a))
			bigPoint = a;
		else if (b.getY() > bigPoint.getY() && !hasPoint(Points, 3, b))
			bigPoint = b;
		else if (c.getY() > bigPoint.getY() && !hasPoint(Points, 3, c))
			bigPoint = c;
		Points[i] = bigPoint;
	}
	return (Points);
}

static Fixed	calculateArea(Point const a, Point const b, Point const c) {
	Fixed	Area;
	Fixed	trapAreas[3];
	Point	*Points;

	Points = sortPoints(a, b, c);
	std::cout << "Points[0]: " << Points[0].getY() << std::endl;
	std::cout << "Points[1]: " << Points[1].getY() << std::endl;
	std::cout << "Points[2]: " << Points[2].getY() << std::endl << std::endl;
	
	trapAreas[0] = ((Points[0].getY() + Points[1].getY()) * (Fixed::max(Points[0].getX(), Points[1].getX()) - Fixed::min(Points[0].getX(), Points[1].getX()))) / Fixed(2.0f);
	std::cout << "Area[0]: " << trapAreas[0] << std::endl;
	trapAreas[1] = ((Points[0].getY() + Points[2].getY()) * (Fixed::max(Points[0].getX(), Points[2].getX()) - Fixed::min(Points[0].getX(), Points[2].getX()))) / Fixed(2.0f);
	std::cout << "Area[1]: " << trapAreas[1] << std::endl;
	trapAreas[2] = ((Points[1].getY() + Points[2].getY()) * (Fixed::max(Points[1].getX(), Points[2].getX()) - Fixed::min(Points[1].getX(), Points[2].getX()))) / Fixed(2.0f);
	std::cout << "Area[2]: " << trapAreas[2] << std::endl;

	Area = trapAreas[0] + trapAreas[1] - trapAreas[2];

	std::cout << "Area: " << Area.toFloat() << std::endl << std::endl;
	
	delete [] Points;
	
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
	std::cout << "Total triangleArea: " << triangleArea1 + triangleArea2 + triangleArea3 << std::endl << std::endl;

	if (triangleArea == triangleArea1 + triangleArea2 + triangleArea3)
		return (true);
	
	return (false);
}
