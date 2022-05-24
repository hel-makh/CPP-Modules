/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:10:36 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/24 14:05:55 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
		return (EXIT_FAILURE);

	Conversion	conv(argv[1]);
	std::cout << conv;

	return (EXIT_SUCCESS);
}
