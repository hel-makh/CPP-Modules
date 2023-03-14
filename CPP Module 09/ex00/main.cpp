/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:36:12 by hel-makh          #+#    #+#             */
/*   Updated: 2023/03/14 22:13:53 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Invalid parameters." << std::endl;
		return (EXIT_FAILURE);
	}

	try {

		BitcoinExchange	btc("data.csv");
		btc.printValues(argv[1]);

	} catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
