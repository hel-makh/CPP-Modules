/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:52:04 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/07 20:29:24 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void) {
	Point	A(10.0f, 30.0f);
	Point	B(0.0f, 0.0f);
	Point	C(20.0f, 0.0f);

	Point	X(10.0f, 15.0f);
	Point	Y(30.0f, 15.0f);

	if (bsp(A, B, C, X))
		std::cout << "+++ Point X is inside triangle ABC." << std::endl;
	else
		std::cout << "--- Point X is not inside triangle ABC." << std::endl;

	if (bsp(A, B, C, Y))
		std::cout << "+++ Point Y is inside triangle ABC." << std::endl;
	else
		std::cout << "--- Point Y is not inside triangle ABC." << std::endl;
}
