/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:38:45 by hel-makh          #+#    #+#             */
/*   Updated: 2023/03/16 14:57:42 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: Invalid parameters." << std::endl;
		return (EXIT_FAILURE);
	}

	try {

		PmergeMe(&argv[1], argc - 1);

	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
