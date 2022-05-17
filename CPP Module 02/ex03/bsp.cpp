
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:11:22 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/08 11:50:40 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed	absFixed(Fixed n) {
	if (n < Fixed(0.0f))
		return (n * Fixed(-1.0f));
	return (n);
}

static Fixed	calculateArea(Point const a, Point const b, Point const c) {
	Fixed	Area;
	Fixed	trapAreas[3];
	
	trapAreas[0] = a.getX() * (b.getY() - c.getY());
	trapAreas[1] = b.getX() * (c.getY() - a.getY());
	trapAreas[2] = c.getX() * (a.getY() - b.getY());

	Area = absFixed((trapAreas[0] + trapAreas[1] + trapAreas[2]) / Fixed(2.0f));
	
	return (Area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	triangleArea;
	Fixed	triangleAreas[3];

	triangleArea = calculateArea(a, b, c);
	triangleAreas[0] = calculateArea(a, b, point);
	triangleAreas[1] = calculateArea(a, point, c);
	triangleAreas[2] = calculateArea(point, b, c);
	
	if (triangleAreas[0] == Fixed(0.0f)
		|| triangleAreas[1] == Fixed(0.0f)
		|| triangleAreas[2] == Fixed(0.0f))
		return (false);

	if (triangleArea == triangleAreas[0] + triangleAreas[1] + triangleAreas[2])
		return (true);
	
	return (false);
}
