/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:03:30 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/07 16:22:27 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void) {
	Fixed a;
	Fixed const b( Fixed(5.05f) * Fixed(2) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	a = b * a;
	std::cout << a << std::endl;

	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	return (EXIT_SUCCESS);
}
