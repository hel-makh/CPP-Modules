/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:52:04 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/08 11:55:18 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void) {
	Point	A(20.0f, -10.0f);
	Point	B(10.0f, -30.0f);
	Point	C(30.0f, -20.0f);

	Point	X(20.0f, -10.1f);
	Point	Y(300.0f, 150.0f);

	if (bsp(A, B, C, X))
		std::cout << "Point X is inside triangle ABC." << std::endl;
	else
		std::cout << "Point X is not inside triangle ABC." << std::endl;

	if (bsp(A, B, C, Y))
		std::cout << "Point Y is inside triangle ABC." << std::endl;
	else
		std::cout << "Point Y is not inside triangle ABC." << std::endl;
		
	return (EXIT_SUCCESS);
}
