/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:12:21 by hel-makh          #+#    #+#             */
/*   Updated: 2023/03/14 23:30:24 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Invalid parameters." << std::endl;
		return (EXIT_FAILURE);
	}

	try {

		std::cout << RPN(argv[1]) << std::endl;

	} catch (std::exception & e) {
		std::cerr << "Error" << std::endl;
	}

	return (EXIT_SUCCESS);
}
