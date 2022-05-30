/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:03:56 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/30 18:26:25 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int	main(void) {
	try {
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(69);	// throws CannotAddNumber exception

		std::cout << "sp:" << std::endl;
		for (std::size_t i = 0; i < sp.getVector().size(); i++) {
			std::cout << i << ": " << sp.getVector()[i] << std::endl;
		}
		std::cout << std::endl;

		std::cout << "sp shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "sp longestSpan: " << sp.longestSpan() << std::endl << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>	vec(10000, 42);
		Span				sp2(10000);

		// sp2.addNumber(46);	// leads to CannotBulkAddNumber exception
		sp2.bulkAdd(vec.begin(), vec.end());

		std::cout << "sp2 size: " << sp2.getSize() << std::endl;

		std::cout << "sp2 shortestSpan: " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 longestSpan: " << sp2.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	return (EXIT_SUCCESS);
}
