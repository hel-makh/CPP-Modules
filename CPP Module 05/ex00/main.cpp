/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:13:45 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/01 14:29:13 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	b("b1", 15);
		std::cout << b << std::endl;
	} catch (std::exception & e) {
		std::cout << "b1, " << e.what() << std::endl;
	}

	try {
		Bureaucrat	b2("b2", 151);
		std::cout << b2 << std::endl;
	} catch (std::exception & e) {
		std::cout << "b2, " << e.what() << std::endl;
	}

	try {
		Bureaucrat	b3("b3", -1);
		std::cout << b3 << std::endl;
	} catch (std::exception & e) {
		std::cout << "b3, " << e.what() << std::endl;
	}

	return (0);
}
